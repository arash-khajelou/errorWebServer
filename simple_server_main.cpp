#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
int main ()
{
  std::cout << "Error Web Server ... !\n";
  int i = 0 ;
  std::string Data = "" ;
  try
    {
      // Create the socket
      ServerSocket server ( 3000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  bool servTest = server.accept ( new_sock );

	  try
	    {
	      if ( servTest )
		{
		  Data = "<a href = \"http://www.google.com\" > salam </a> ";
		  new_sock << Data ;
		  new_sock << "\n<a href = \"http://www.google.com\"><h1>salam</h1></a>";
		}
	      if ( new_sock.iRecv(Data) )
		{
		  new_sock << Data ;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
