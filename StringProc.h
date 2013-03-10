#ifndef STRINGPROC_H
#define STRINGPROC_H

#include <string>

class StringProc {
	std::string pString ;
	std::string directory;
	std::string protocol;
	std::string request;
public :
	StringProc (std::string);
	StringProc ();
	void process ();
	std::string getDir ();
	std::string getProto ();
	std::string getReq ();
	void setStringProc (std::string );
};

#endif
