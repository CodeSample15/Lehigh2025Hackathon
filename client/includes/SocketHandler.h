#ifndef _SOCKET_HANDLER_H__
#define _SOCKET_HANDLER_H__

/*
    Static Network manager initalized at each player startup 
    in order to communicate with the server 
*/

#include <string>
#include "sockpp/tcp_connector.h"

enum REQUEST_TYPE
{
    SYNC, GET_VAR, 
};

class SocketHandler
{
    private:
        static std::string IP;
        static in_port_t port;

        static sockpp::tcp_connector conn;
    public:
        static int Startup(std::string _IP, in_port_t _port);

        static std::string Read();
        static void Send(std::string varName);
        static void Sync(std::string send, std::string& receive);
};

#endif