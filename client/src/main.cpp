#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"
#include <sstream>


//  Just gonna assume theres only one comma for now


int main(int argc, char* argv[])
{
    std::string host = "127.0.0.1";
    Client player(host);


    while(1){
        SocketHandler::Send("Hello ");
        SocketHandler::Send("Hello ");
        player.Sync();
        player.DebugPrint();
    }
    

    /*
    while(1)
    {
        player.Update();
        continue;
    }
        */

    

    return 0;
}