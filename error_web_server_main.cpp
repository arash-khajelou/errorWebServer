#include "ServerSocket.h"
#include "SocketException.h"
#include "StringProc.h"
#include "tools.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main () {
	std::system("clear");
	std::cout << "\nError Web Server " 
			  << "\n================="
			  << "\n\t this is a simple web server "
			  << "\n\t written by :"
			  << "\n\t\t Arash Khajelou " 
			  << "\n Error Web Server is running ...\n\n";
	std::ifstream cnf ("config.conf");
	if (!cnf){
		std::cout << "conf file not found !";
		return 0 ;
	}
	std::string wwwDir ;
	getline(cnf , wwwDir);
	std::cout << wwwDir ;
	cnf.close () ;
 	try { // starting the body of expection error
		ServerSocket server ( 8081 ); // creating socket in port 3000
    while ( true ) { // main loop
			ServerSocket connectedSock; // accepted socket	created to client
			bool servTest = server.accept ( connectedSock ); // generatig IP and port ...
			std::string recvString = " ";
			StringProc pStr ;
			try {
				if ( servTest ) {
	      	if ( connectedSock.iRecv(recvString) ) {
		  			pStr.setStringProc (recvString);
		  			pStr.process();
		  		}
		  		// you should set your wwww (i.e /) directory in the config.conf file
		  			wwwDir.append(pStr.getDir());
					writeBody (connectedSock, wwwDir);
				}
	    }
			catch ( SocketException& ) {}
		}
	}
	catch ( SocketException& e ) {
  	std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}
	return 0;
}
