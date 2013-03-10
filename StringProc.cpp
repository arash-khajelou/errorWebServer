#include "StringProc.h"

#include <iostream>

StringProc::StringProc(std::string s){
	pString = s ;
	request = " " ;
}
StringProc::StringProc(){
	pString = " " ;
	request = " " ;
}
void StringProc::process() {
	/* GET /Dir_1/Dir_2/... HTTP/1.1 Host: localhost:3000 */
	int i = 0 ;
	while (pString[i] != ' '){
		request[i] = pString[i];
		std::cout << i << request ;
		i++ ;
	}
	i++ ;
	int j = i ;
	while (pString[i] != ' '){
		directory[i-j] = pString[i];
		std::cout << pString[i]; // should be deleted
		i++ ;
	}
	i++ ;
	int k = i ;
	while (pString[i] != '\n' and pString[i] != ' '){
		protocol[i-k] = pString[i];
		std::cout << pString[i] ; // shuld be deleted
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