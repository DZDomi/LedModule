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
    
    this->font->LoadFont("fonts/8x13.bdf");
    
    this->matrix->SetBrightness(100);
    
}

void Led::printText(string text){
    rgb_matrix::DrawText(this->matrix, *this->font, 0, 0 + this->font->baseline(), this->color, NULL, text.c_str());
    sleep(10000);
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
