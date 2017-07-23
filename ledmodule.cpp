#include <iostream>

#include "communicator.h"
#include "message.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
	Communicator *com = Communicator::getInstance("/tmp/test.sock");
	com->acceptConnections();
	bool closed = false;

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	tutorial::AddressBook address_book;

	while(!closed){
		string data = "";
		Action action = com->getRequest(data);
		switch(action){
			case Action::text:
				cout << "text" << endl;
				//TODO: Implement Me
				break;
			case Action::picture:
				cout << "picture" << endl;
				//TODO: Implement Me
				break;
			case Action::gif:
				cout << "gif" << endl;
				//TODO: Implement Me
				break;
			case Action::video:
				cout << "video" << endl;
				//TODO: Implement Me
				break;
			case Action::closed:
				closed = true;
				break;
		}
		cout << data << endl;
	}
	delete com;
}
