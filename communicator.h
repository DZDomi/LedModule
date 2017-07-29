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

class Communicator {
	public:
		static Communicator* getInstance(string);
		//Needed for singletons
		Communicator(Communicator const&) = delete;
		void operator=(Communicator const&) = delete;
		~Communicator();
		
		void acceptConnections();
		string getRequest();
		
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
