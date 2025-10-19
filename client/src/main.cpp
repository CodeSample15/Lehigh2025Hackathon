#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"

int main(int argc, char* argv[])
{
    std::string host = "192.168.0.198";
    Client player(host);

    std::string read;

    while(1)
    {
        player.Update();
    }

    return 0;
}