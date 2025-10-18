#include "SocketHandler.h"

std::string SocketHandler::IP;
in_port_t SocketHandler::port;

bool SocketHandler::Startup(std::string _IP)
{
    IP = _IP;
    port = 65312;

    sockpp::initialize();
    sockpp::tcp_connector conn;

    // Attempt to connect with a 10 sec timeout.
    auto res = conn.connect(IP, port);
    if (!res)
    {
        std::cerr << "Error connecting to server at: '" << IP << "':\n\t" << res.error_message()
                  << std::endl;
        return false;
    }

    std::cout << "Created a connection from " << conn.address() << std::endl;

    std::string s, sret;
    while (getline(std::cin, s) && !s.empty())
    {
        const size_t N = s.length();

        // TODO: Do we need to check length (res.value()) for write or read?
        if (auto res = conn.write(s); res != N)
        {
            std::cerr << "Error writing to the TCP stream: " << res.error_message() << std::endl;
            break;
        }

        sret.resize(N);
        if (auto res = conn.read_n(&sret[0], N); res != N)
        {
            std::cerr << "Error reading from TCP stream: " << res.error_message() << std::endl;
            break;
        }

        std::cout << sret << std::endl;
    }

    return true;
}