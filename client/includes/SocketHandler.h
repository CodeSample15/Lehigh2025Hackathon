#ifndef _SOCKET_HANDLER_H__
#define _SOCKET_HANDLER_H__

/*
    Static Network manager initalized at each player startup 
    in order to communicate with the server 
*/

#include <string>
#include "sockpp/tcp_connector.h"

class SocketHandler
{
    private:
        static std::string IP;
        static in_port_t port;
    public:
        static int Startup(std::string _IP);

        static void SendString(std::string varName);

};

#endif