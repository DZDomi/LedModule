#include <iostream>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "led-matrix.h"
#include "transformer.h"
#include "graphics.h"

using namespace std;
using namespace rgb_matrix;

class Led {
	public:
		static Led* getInstance();
		//Needed for singletons
		Led(Led const&) = delete;
		void operator=(Led const&) = delete;
		~Led();
		
		void printText(string text);
		
	private:
		static Led* instance;
		Led();
		static void setUpInterruptHandler();
		static void interrupt(int);
        
        static void showText(Led *led, string text);
        
        void calculateColor(int *continuum, int *red, int *green, int *blue);
        void prepareThread(string text);
        
        RGBMatrix *matrix;
        Font font;
        Color color;
        
        bool threadStarted = false;
        bool canceled = false;
};
