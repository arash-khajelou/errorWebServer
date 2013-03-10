#include "StringProc.h"

#include <iostream>
#include <sstream>

StringProc::StringProc(std::string s){
	pString = s ;
}
StringProc::StringProc(){
	pString = " " ;
}
void StringProc::process() {
	/* GET /Dir_1/Dir_2/... HTTP/1.1 Host: localhost:3000 */
	std::istringstream splitString(pString);
	splitString >> pString;
	std::string temp ;
	splitString >> temp;
	if (temp != "/favicon.ico")
		directory = temp ;
	splitString >> protocol;
}
std::string StringProc::getDir(){
	return directory ;
}
std::string StringProc::getProto(){
	return protocol ;
}
std::string StringProc::getReq(){
	return request ;
}
void StringProc::setStringProc (std::string s){
	pString = s ;
}