#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"
#include <sstream>


//  Just gonna assume theres only one comma for now


int main(int argc, char* argv[])
{
    ParsePacket("test,ing");
    std::string host = "192.168.0.198";
    Client player(host);

    std::string read;

    /*
    while(1)
    {
        player.Update();
        continue;
    }
        */

    

    return 0;
}