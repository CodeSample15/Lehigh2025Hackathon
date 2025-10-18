#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"

int main(int argc, char* argv[])
{
    std::string IP = "127.0.0.1";
    Client player(IP);

    int16_t port = 12345;
    sockpp::initialize();
    sockpp::tcp_connector conn;


    return 0;
}