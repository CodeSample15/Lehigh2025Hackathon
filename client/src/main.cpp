#include <iostream>
#include "Client.h"

#include "sockpp/tcp_connector.h"
#include "sockpp/version.h"

int main(int argc, char* argv[])
{
    std::string IP = "127.0.0.1";
    Client player(IP);

    std::string host = (argc > 1) ? argv[1] : "localhost";
    in_port_t port = (argc > 2) ? atoi(argv[2]) : sockpp::TEST_PORT;

    sockpp::initialize();
    sockpp::tcp_connector conn;

    // Attempt to connect with a 10 sec timeout.
    auto res = conn.connect(host, port);
    if (!res)
    {
        std::cerr << "Error connecting to server at: '" << host << "':\n\t" << res.error_message()
             << std::endl;
        return 1;
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

    return 0;
}