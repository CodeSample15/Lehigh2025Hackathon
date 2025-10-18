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
    //  Retrieve PID from server
    //  Port 65312

    std::cout << "Connection to IP: " << IP << " \n";
    return true;
}