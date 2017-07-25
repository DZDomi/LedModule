#include <iostream>

#include "communicator.h"

using namespace std;

int main(int argc, char *argv[]) {
	Communicator *com = Communicator::getInstance("/tmp/test.sock");
	com->acceptConnections();
	bool closed = false;

    //GOOGLE_PROTOBUF_VERIFY_VERSION;

	//tutorial::AddressBook address_book;

	while(!closed){
		string data = "";
		Action action = com->getRequest(data);
		switch(action){
			case Action::TEXT:
				cout << "text" << endl;
				//TODO: Implement Me
				break;
			case Action::PICTURE:
				cout << "picture" << endl;
				//TODO: Implement Me
				break;
			case Action::GIF:
				cout << "gif" << endl;
				//TODO: Implement Me
				break;
			case Action::VIDEO:
				cout << "video" << endl;
				//TODO: Implement Me
				break;
			case Action::CLOSED:
				closed = true;
				break;
		}
		cout << data << endl;
	}
	delete com;
}
