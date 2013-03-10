#include "ServerSocket.h"
#include "SocketException.h"
#include "StringProc.h"

#include <string>
#include <iostream>

int main () {
 	try { // starting the body of expection error

    	ServerSocket server ( 2013 ); // creating socket in port 3000

      	while ( true ) { // main loop

	  		ServerSocket connected_sock; // accepted socket created to client
	  		bool servTest = server.accept ( connected_sock ); // generatig IP and port ...
	  		std::string recvString = " ";
	  		StringProc pStr ;
	  		try {
	      		if ( servTest ) {
	      			if ( connected_sock.iRecv(recvString) ) {
		  				pStr.setStringProc (recvString);
		  				pStr.process();
					}
		  			//recvString = "<a href = \"http://www.google.com\" > google WebSie </a> ";
		  			connected_sock << recvString ;
		  			std::cout<< "\n" << pStr.getDir() << "\n" << pStr.getProto();
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
