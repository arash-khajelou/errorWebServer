# Makefile for Error Web Server
#

error_web_server_objects = ServerSocket.o Socket.o simple_server_main.o


all : error_web_server

error_web_server: $(error_web_server_objects)
	g++ -o errorWebServer $(error_web_server_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
simple_server_main: simple_server_main.cpp


clean:
	rm -f *.o errorWebServer
