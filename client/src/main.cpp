#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"
#include <sstream>


//  Just gonna assume theres only one comma for now


int main(int argc, char* argv[])
{
    std::string host = "127.0.0.1";
    Client player(host, 65312);


    while(1){
        player.Sync();
        //player.DebugPrint();
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