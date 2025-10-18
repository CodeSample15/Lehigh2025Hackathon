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
    
    if(!SocketHandler::Startup(IP))
        return false;

    return true;
}