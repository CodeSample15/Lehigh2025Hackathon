#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"

int main(int argc, char* argv[])
{
    std::string host = "127.0.0.1";
    Client player(host);

    while(1)
    {
        player.Update();
    }

    return 0;
}