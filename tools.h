#ifndef TOOLS_h
#define TOOLS_h

#include "ServerSocket.h"
#include <fstream>

void writeBody (ServerSocket & connectedSocket, std::string addr) {
	std::ifstream htmlFile (addr.c_str());
	if (! htmlFile ) 
		connectedSocket << "Error 404 ! \nPage Not Found" ;
	else {
		while ( htmlFile ) {
			std::string wLine ;
			getline(htmlFile , wLine);
			connectedSocket << wLine << "\n";
		}
	}
}


#endif
