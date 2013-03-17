# Makefile for Error Web Server
#

error_web_server_objects = tools.o ServerSocket.o Socket.o StringProc.o error_web_server_main.o


all : error_web_server

error_web_server: $(error_web_server_objects)
	g++ -o errorWebServer $(error_web_server_objects)


StringProc: StringProc.cpp
Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
error_web_server_main: error_web_server_main.cpp
tools:tools.cpp

clean:
	rm -f *.o errorWebServer
