#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
int main ()
{
  std::cout << "Error Web Server ... !\n";
  int i = 0 ;
  try
    {
      // Create the socket
      ServerSocket server ( 8081 );

      while ( true )
	{

	  ServerSocket new_sock;
	  bool servTest = server.accept ( new_sock );

	  try
	    {
	      if ( servTest )
		{
		  std::string data;
		  data = "<a href = \"http://www.google.com\" > salam </a> ";
		  new_sock << data ;
		  new_sock << "\n<a href = \"http://www.google.com\"><h1>salam</h1></a>";
		  i++ ;
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
