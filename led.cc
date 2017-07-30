#include "led.h"

Led* Led::instance = nullptr;

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
    this->prepareThread();
}

void Led::showText(Led *led, string text){
    int continuum = rand() % 1000 + 1, red, green, blue;
    int pos = led->matrix->width();
    while(!led->canceled){
        
        led->matrix->Clear();
        
        led->calculateColor(&continuum, &red, &green, &blue);
        led->color = Color(red, green, blue);
        
        int len = rgb_matrix::DrawText(led->matrix, led->font, pos, (led->font.baseline() + led->matrix->height()) / 2, led->color, NULL, text.c_str());
        
        pos -= 1;
        if(pos + len < 0){
            pos = led->matrix->width();
            //break;
        }
        usleep(30000);
    }
    cout << "Stopping" << endl;
}

void Led::prepareThread() {
    //Tell currently running threads to stop execution
    this->canceled = true;
    cout << "canceled set to true" << endl;
    
    this->runningThread = thread(&Led::showText, this, "Hello");
    this->runningThread.detach();
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
