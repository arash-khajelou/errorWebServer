#include "tools.h"

void writeBody (ServerSocket & connectedSocket, std::string addr){
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