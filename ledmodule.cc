#include <iostream>
#include <sstream>

#include "led-matrix.h"

#include "communicator.h"
#include "led.h"
#include "models/request.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    Led *led = Led::getInstance();
	Communicator *com = Communicator::getInstance("/tmp/test.sock");
	com->acceptConnections();
    
    led->printText("Hello World");
    
	while(1){
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
				cout << request.textrequest().text() << endl;
				break;
			case ledmodule::Request::PICTURE:
				cout << "picture" << endl;
				//TODO: Implement Me
				break;
			case ledmodule::Request::GIF:
				cout << "gif" << endl;
				//TODO: Implement Me
				break;
			case ledmodule::Request::VIDEO:
				cout << "video" << endl;
				//TODO: Implement Me
				break;
		}
	}
	delete com;
    google::protobuf::ShutdownProtobufLibrary();
    
    return EXIT_SUCCESS;
}
