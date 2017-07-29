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

Led::Led() {
    RGBMatrix::Options options;
    options.hardware_mapping = "adafruit-hat-pwm";
    options.chain_length = 4;
    options.show_refresh_rate = false;
    rgb_matrix::RuntimeOptions runtime;
    runtime.drop_privileges = 1;
    
    matrix = rgb_matrix::CreateMatrixFromOptions(options, runtime);
    matrix->ApplyStaticTransformer(rgb_matrix::UArrangementTransformer(options.parallel));
    
    
}

void Led::printText(string text){
    
}

Led::~Led() {
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
	delete instance->matrix;
}
