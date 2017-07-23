#include <iostream>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

enum Action {
	text = 1,
	picture = 2,
	gif = 3,
	video = 4,
	closed = 5
};

class Communicator {
	public:
		static Communicator* getInstance(string);
		//Needed for singletons
		Communicator(Communicator const&) = delete;
		void operator=(Communicator const&) = delete;
		~Communicator();
		
		void acceptConnections();
		Action getRequest(string &data);
		
	private:
		static Communicator* instance;
		Communicator(string);
		static void setUpInterruptHandler();
		static void interrupt(int);
		
		void createSocket();
		
		string socketName;
		int server;
		int client;
		
};