#include "SocketHandler.h"

std::string SocketHandler::IP;
in_port_t SocketHandler::port;
sockpp::tcp_connector SocketHandler::conn;

int SocketHandler::Startup(std::string _IP, in_port_t _port)
{
    IP = _IP;
    port = _port;

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

std::string SocketHandler::Read()
{
    std::vector<char> buf(1024);
    auto res = conn.read(&buf[0], buf.size());

    std::string ret(buf.begin(), buf.end());
    size_t trunc = ret.find('\0');
    ret = ret.substr(0, trunc);

    return ret;
}

void SocketHandler::Send(std::string varName)
{
    conn.write_n(varName.c_str(), varName.length());

    std::cout << Read() << "\n";
    return;
}