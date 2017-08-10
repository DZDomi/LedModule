#include <iostream>
#include <sstream>
#include <fstream>

#include "led-matrix.h"

#include "communicator.h"
#include "led.h"
#include "models/request.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    Led *led = Led::getInstance();
	Communicator *com = Communicator::getInstance("/var/run/led.sock");
	com->acceptConnections();
    
	while(true){
        string data;
        try {
            data = com->getRequest();
        } catch(std::runtime_error &e){
            cout << e.what() << endl;
            break;
        }
        
        ledmodule::Request request;
        request.ParseFromString(data);
        
        cout << "Message from: " << request.sender() << endl;
        cout << request.action() << endl;
        
		switch(request.action()){
            case ledmodule::Request::TEXT:
                led->printText(request.textrequest().text());
				cout << request.textrequest().text() << endl;
				break;
			case ledmodule::Request::PICTURE:
				cout << "picture" << endl;
				//TODO: Implement Me
				break;
			case ledmodule::Request::GIF: {
                led->printPicture(request.gifrequest().gif());
				break;
            }
			case ledmodule::Request::VIDEO:
				cout << "video" << endl;
				//TODO: Implement Me
				break;
            case ledmodule::Request::CANCEL:
                led->cancelAction();
                break;
		}
	}
	delete com;
    google::protobuf::ShutdownProtobufLibrary();
    
    return EXIT_SUCCESS;
}
