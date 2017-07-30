#include "communicator.h"

Communicator* Communicator::instance = nullptr;

Communicator* Communicator::getInstance(string socketName){
	if(instance != nullptr){
		return instance;
	}
	instance = new Communicator(socketName);
	setUpInterruptHandler();
	return instance;
}

Communicator::Communicator(string socketName) {
	this->socketName = socketName;
	this->createSocket();
}

void Communicator::createSocket() {
	struct sockaddr_un server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, this->socketName.c_str(), sizeof(server_addr.sun_path) - 1);
	
	server = socket(PF_UNIX, SOCK_STREAM, 0);
	if(!server){
		perror("Unable to get socket");
		exit(-1);
	}
	int enable = 1;
	if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0){
		perror("Unable to set socket options");
		exit(-1);
	}
	
	if(::bind(server, (const struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		perror("Unable to bind the socket");
		exit(-1);
	}
	
	if(listen(server, SOMAXCONN) < 0){
		perror("Unable to listen at socket");
		exit(-1);
	}
}

void Communicator::acceptConnections() {
	struct sockaddr_in client_addr;
	socklen_t clientLength = sizeof(client_addr);
		
	client = accept(server, (struct sockaddr *) &client_addr, &clientLength);
}

string Communicator::getRequest() {
	int bufLength = 1024;
	char buffer[bufLength + 1];
	
    int contentLength = -1;
    string data = "";
    
    recv(client, &contentLength, sizeof(int), 0);
    cout << contentLength << endl;
    
	int bytesRead = -1;
	while((bytesRead = recv(client, buffer, bufLength, 0)) > 0){
		data.append(buffer, bytesRead);
	}
	//Connection closed
	if(bytesRead == 0){
		throw std::runtime_error("Connection closed");
	}
	//data = data.substr(0, data.length() - 1);
	return data;
}

Communicator::~Communicator() {
	unlink(this->socketName.c_str());
}

void Communicator::setUpInterruptHandler() {
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = instance->interrupt;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
}

void Communicator::interrupt(int) {
	unlink(instance->socketName.c_str());
}
