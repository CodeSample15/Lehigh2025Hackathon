#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"
#include <sstream>


//  Just gonna assume theres only one comma for now
const char del = ',';
void ParsePacket(std::string dictionaryPair)
{
    auto pos = dictionaryPair.find(del);

    std::string s1 = dictionaryPair.substr(0, pos);
    std::string s2 = dictionaryPair.substr(pos, dictionaryPair.size());
};

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