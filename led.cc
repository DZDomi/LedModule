#include "led.h"

Led* Led::instance = nullptr;
std::mutex m;
std::condition_variable cond_var;

Led* Led::getInstance(){
	if(instance != nullptr){
		return instance;
	}
	instance = new Led();
	setUpInterruptHandler();
	return instance;
}

Led::Led() : color(255, 255, 0) {
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
    this->prepareThread(text);
}

void Led::showText(Led *led, string text){
    std::unique_lock<std::mutex> lck(m);
    int continuum = rand() % 1000 + 1, red, green, blue;
    int pos = led->matrix->width();
    while(!cond_var.wait_for(lck, std::chrono::microseconds(30000), [&]{ return led->canceled; })){
        
        led->matrix->Clear();
        
        led->calculateColor(&continuum, &red, &green, &blue);
        led->color = Color(red, green, blue);
        
        int len = rgb_matrix::DrawText(led->matrix, led->font, pos, (led->font.baseline() + led->matrix->height()) / 2, led->color, NULL, text.c_str());
        
        pos -= 1;
        if(pos + len < 0){
            pos = led->matrix->width();
            //break;
        }
    }
    cond_var.notify_one();
    cout << "Stopping" << endl;
}

void Led::prepareThread(string text) {
    //Tell currently running thread to stop execution
    if(this->threadStarted){
        this->canceled = true;
        cout << "canceled set to true" << endl;
        std::unique_lock<std::mutex> lck(m);
        cout << "Lock" << endl;
        cond_var.notify_one();
        cout << "Notified" << endl;
        cond_var.wait(lck);
        this->canceled = false;
        cout << "Got Message from Thread" << endl;
        //this->canceled = false;
    }
    thread t = thread(&Led::showText, this, text);
    t.detach();
    this->threadStarted = true;
    cout << "Starting Thread" << endl;
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
