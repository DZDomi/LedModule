#include "led.h"

Led* Led::instance = nullptr;
std::mutex m;
std::condition_variable cond_var;

typedef int64_t tmillis_t;
static const tmillis_t distant_future = (1LL<<40); // that is a while.

struct ImageParams {
    ImageParams() : anim_duration_ms(distant_future), wait_ms(1500),
                    anim_delay_ms(-1), loops(-1) {}
    tmillis_t anim_duration_ms;  // If this is an animation, duration to show.
    tmillis_t wait_ms;           // Regular image: duration to show.
    tmillis_t anim_delay_ms;     // Animation delay override.
    int loops;
};

struct FileInfo {
    ImageParams params;      // Each file might have specific timing settings
    bool is_multi_frame;
    StreamIO *content_stream;
};

Led* Led::getInstance(){
	if(instance != nullptr){
		return instance;
	}
	instance = new Led();
	setUpInterruptHandler();
	return instance;
}

Led::Led() : color(255, 255, 0) {
    
    Magick::InitializeMagick(NULL);
    
    RGBMatrix::Options options;
    options.hardware_mapping = "adafruit-hat-pwm";
    options.chain_length = 4;
    options.show_refresh_rate = false;
    
    rgb_matrix::RuntimeOptions runtime;
    runtime.drop_privileges = 1;
    
    this->matrix = rgb_matrix::CreateMatrixFromOptions(options, runtime);
    this->matrix->ApplyStaticTransformer(rgb_matrix::UArrangementTransformer(options.parallel));
    
    this->font = Font();
    this->font.LoadFont("fonts/8x13.bdf");
    
    this->matrix->SetBrightness(100);
    
    //Initialize random number generator
    srand(time(NULL));
    
}

void Led::printText(string text){
    this->prepareThread(&Led::showText, text);
}

void Led::printPicture(string data){
    this->prepareThread(&Led::showPicture, data);
}

void Led::showText(Led *led, string text){
    std::unique_lock<std::mutex> lck(m);
    int continuum = rand() % 1000 + 1, red, green, blue;
    int pos = led->matrix->width();
    cout << "Got text started" << endl;
    while(!cond_var.wait_for(lck, std::chrono::microseconds(30000), [&]{ return led->canceled; })){
        
        cout << "Clearing matrix" << endl;
        led->matrix->Clear();
        
        led->calculateColor(&continuum, &red, &green, &blue);
        led->color = Color(red, green, blue);
        
        int len = rgb_matrix::DrawText(led->matrix, led->font, pos, (led->font.baseline() + led->matrix->height()) / 2, led->color, NULL, text.c_str());
        
        cout << "Drwaing text" << endl;
        
        pos -= 1;
        if(pos + len < 0){
            pos = led->matrix->width();
            //break;
        }
    }
    //Tell the main thread that we finished execution
    cond_var.notify_one();
}

void Led::showPicture(Led *led, string data){
    std::unique_lock<std::mutex> lck(m);
    while(!cond_var.wait_for(lck, std::chrono::microseconds(30000), [&]{ return led->canceled; })){
        
        led->matrix->Clear();
        
        FrameCanvas *offScreenCanvas = instance->matrix->CreateFrameCanvas();
        std::vector<Magick::Image> imageSequence;
        readImageFromBuffer(data, &imageSequence);
        cout << "read success" << endl;
        
        FileInfo *fileInfo = new FileInfo();
        fileInfo->params = ImageParams();
        fileInfo->is_multi_frame = imageSequence.size() > 1;
        fileInfo->content_stream = new MemStreamIO();
        
        StreamWriter out(fileInfo->content_stream);
        
        for (size_t i = 0; i < imageSequence.size(); i++) {
            const Magick::Image &img = imageSequence[i];
            int64_t delay_time_us;
            if (fileInfo->is_multi_frame) {
                delay_time_us = img.animationDelay() * 10000; // unit in 1/100s
            } else {
                delay_time_us = fileInfo->params.wait_ms * 1000;  // single image.
            }
            
            if (delay_time_us <= 0)  {
                delay_time_us = 100 * 1000;  // 1/10sec
            }
            storeInStream(img, delay_time_us, offScreenCanvas, &out);
      }
      
        displayAnimation(fileInfo, offScreenCanvas);
        cout << "Animation finished" << endl;
    }
    cout << "Out of loop" << endl;
    //Tell the main thread that we finished execution
    cond_var.notify_one();
    cout << "Notified" << endl;
}

void Led::displayAnimation(const FileInfo *fileInfo, FrameCanvas *offscreen_canvas) {
  const tmillis_t duration_ms = (fileInfo->is_multi_frame ? fileInfo->params.anim_duration_ms : fileInfo->params.wait_ms);
  rgb_matrix::StreamReader reader(fileInfo->content_stream);
  int loops = fileInfo->params.loops;
  const tmillis_t end_time_ms = getTimeInMillis() + duration_ms;
  const tmillis_t override_anim_delay = fileInfo->params.anim_delay_ms;
  for (int k = 0; (loops < 0 || k < loops) && !instance->canceled && getTimeInMillis() < end_time_ms; ++k) {
    uint32_t delay_us = 0;
    while (!instance->canceled && getTimeInMillis() <= end_time_ms && reader.GetNext(offscreen_canvas, &delay_us)) {
      const tmillis_t anim_delay_ms = override_anim_delay >= 0 ? override_anim_delay : delay_us / 1000;
      const tmillis_t start_wait_ms = getTimeInMillis();
      offscreen_canvas = instance->matrix->SwapOnVSync(offscreen_canvas);
      const tmillis_t time_already_spent = getTimeInMillis() - start_wait_ms;
      sleepMillis(anim_delay_ms - time_already_spent);
      cout << "Sleeping finished" << endl;
    }
    reader.Rewind();
  }
}

void Led::storeInStream(const Magick::Image &img, int delay_time_us, FrameCanvas *scratch, StreamWriter *output) {
  scratch->Clear();
  const int x_offset = 0;
  const int y_offset = 0;
  for (size_t y = 0; y < img.rows(); ++y) {
    for (size_t x = 0; x < img.columns(); ++x) {
      const Magick::Color &c = img.pixelColor(x, y);
      if (c.alphaQuantum() < 256) {
        scratch->SetPixel(x + x_offset, y + y_offset,
                          ScaleQuantumToChar(c.redQuantum()),
                          ScaleQuantumToChar(c.greenQuantum()),
                          ScaleQuantumToChar(c.blueQuantum()));
      }
    }
  }
  output->Stream(*scratch, delay_time_us);
}

void Led::readImageFromBuffer(string data, std::vector<Magick::Image> *result){
    std::vector<Magick::Image> frames;
    Magick::Blob blob = Magick::Blob(static_cast<const void *>(data.c_str()), data.size());
    readImages(&frames, blob);
    if (frames.size() > 1) {
        Magick::coalesceImages(result, frames.begin(), frames.end());
    } else {
        result->push_back(frames[0]);   // just a single still image.
    }
    
    //const int img_width = (*result)[0].columns();
    //const int img_height = (*result)[0].rows();
    //const float width_fraction = (float) instance->matrix->width() / img_width;
    //const float height_fraction = (float) instance->matrix->height() / img_height;
    
    for (size_t i = 0; i < result->size(); ++i) {
        (*result)[i].scale(Magick::Geometry(instance->matrix->width(), instance->matrix->height()));
    }
}

tmillis_t Led::getTimeInMillis() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

void Led::sleepMillis(tmillis_t milli_seconds) {
  if (milli_seconds <= 0) return;
  struct timespec ts;
  ts.tv_sec = milli_seconds / 1000;
  ts.tv_nsec = (milli_seconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
}

void Led::prepareThread(void (*func)(Led *, string), string text) {
    //Tell currently running thread to stop execution
    if(this->threadStarted){
        this->canceled = true;
        std::unique_lock<std::mutex> lck(m);
        //Tell the current running thread to check the canceled variable
        cond_var.notify_one();
        //Wait for the thread to stop executing
        cond_var.wait(lck);
        this->canceled = false;
    }
    thread t = thread(func, this, text);
    t.detach();
    this->threadStarted = true;
}

void Led::calculateColor(int *continuum, int *red, int *green, int *blue){

    *continuum += 1;
    *continuum %= 3 * 255;

    *red = 0;
    *green = 0;
    *blue = 0;

    if (*continuum <= 255){
        int c = *continuum;
        *blue = 255 - c;
        *red = c;
    } else if (*continuum > 255 and *continuum <= 511){
        int c = *continuum - 256;
        *red = 255 - c;
        *green = c;
    } else {
        int c = *continuum - 512;
        *green = 255 - c;
        *blue = c;
    }
}


Led::~Led() {
    matrix->Clear();
    delete matrix;
}

void Led::setUpInterruptHandler() {
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = instance->interrupt;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
}

void Led::interrupt(int) {
    instance->matrix->Clear();
	delete instance->matrix;
}
