#include <iostream>
#include <sstream>

#include "communicator.h"
#include "models/request.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    ledmodule::Request request;
    string data;
    
	Communicator *com = Communicator::getInstance("/tmp/test.sock");
	com->acceptConnections();

	while(1){
        try {
            data = com->getRequest();
        } catch(std::runtime_error &e){
            cout << "Connection from client closed" << endl;
            break;
        }
        
        request.ParseFromString(data);
        
        cout << request.sender() << endl;
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
