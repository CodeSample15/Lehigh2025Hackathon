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
    //  TODO: Different Implementations based on windows / linux 

    //  Retrieve PID from server
    //  Port 65312
    
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
    std::string readValue;
    std::cin >> readValue;
    SocketHandler::Send(readValue);
}