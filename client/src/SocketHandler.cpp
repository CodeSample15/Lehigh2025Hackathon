#include "SocketHandler.h"

std::string SocketHandler::IP;
in_port_t SocketHandler::port;
sockpp::tcp_connector SocketHandler::conn;

int SocketHandler::Startup(std::string _IP)
{
    IP = _IP;
    port = 65312;

    sockpp::initialize();

    // Attempt to connect with a 10 sec timeout.
    auto res = conn.connect(IP, port);
    if (!res)
    {
        std::cerr << "Error connecting to server at: '" << IP << "':\n\t" << res.error_message()
                  << std::endl;
        return false;
    }

    std::cout << "Created a connection from " << conn.address() << std::endl;
    

    return true;
}

void SocketHandler::Poll(std::string varName)
{
    char buf[37];
    auto res = conn.read(buf, sizeof(buf));

    for(char c : buf)
        std::cout << c;

    std::cout << "\n";

    conn.write_n("Luke gay", 8)
}