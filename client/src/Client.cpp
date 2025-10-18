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

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    std::cout << "Connection to IP: " << IP << " \n";
    return true;
}