#include "Client.h"

std::pair<std::string, std::string> Client::ParsePacket(std::string dictionaryPair)
{
    auto pos = dictionaryPair.find(del);

    std::string s1 = dictionaryPair.substr(0, pos);
    std::string s2 = dictionaryPair.substr(pos, dictionaryPair.size());

    return {s1, s2};
};

/* Public */

Client::Client(std::string IP)
{
    
    if (!Connect(IP))
    {
        std::cerr << "Connection failed to initalize " << IP << "\n";
        return;
    }
    
}

bool Client::Connect(std::string IP)
{
    SocketHandler::Startup(IP);
    UUID = SocketHandler::Read();

    std::cout << "UUID: " << UUID << " \n";
    return true;
}

template <typename T>
T Client::GetVar(std::string varName)
{
    
}
template <typename T>
T Client::SetVar(std::string varName)
{

}

void Client::Update()
{
    std::string readValue = " ";
    SocketHandler::Send(readValue);
}
void Client::Sync()
{
    std::string receive = "";
    receive = SocketHandler::Read();        //  Either read EVERY update, or loop until no more sent  //

    auto pair = ParsePacket(receive);
    AddDictElement(pair.first, pair.second);    

    //std::string send = "Data to Send";
    //SocketHandler::Send(send);
}

void Client::AddDictElement(std::string key, std::string value)
{
    attribs[key] = value;
}

void Client::DictPrintDebug()
{
    for(auto pair : attribs)
    {
        std::cout << pair.first <<  " :: " << pair.second << "\n";
    }
}