#include "StringProc.h"

StringProc::StringProc(std::string s){
	pString = s ;
}
StringProc::StringProc(){
	pString = " " ;
}
void StringProc::process() {
	/* GET /Dir_1/Dir_2/... HTTP/1.1 Host: localhost:3000 */
	int i = 0 ;
	while (pString[i] != ' '){
		request[i] = pString[i];
		i++ ;
	}
	i++ ;
	int j = i ;
	while (pString[i] != ' '){
		directory[i-j] = pString[i];
		i++ ;
	}
	i++ ;
	int k = i ;
	while (pString[i] != ' '){
		protocol[i-k] = pString[i];
		i++ ;
	}
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