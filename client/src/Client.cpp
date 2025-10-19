#include "Client.h"

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

    std::string Dict = SocketHandler::Read();

    
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
    std::string readValue;
    std::getline(std::cin, readValue);
    SocketHandler::Send(readValue);
}

void Client::AddDictElement(std::string key, std::string value)
{
    attribs[key] = value;
}