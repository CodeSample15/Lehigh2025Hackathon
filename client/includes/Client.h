#ifndef _CLIENT_H__
#define _CLIENT_H__

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "SocketHandler.h"

struct ClientAttributes
{
    
};

class Client
{
private:
    const static std::string ip;
    int clientSocket;

    std::string UUID = ""; 
    std::vector<std::function<void()>> playerActions;
public:
    Client(std::string IP);

    /* Server Sync */
    bool Connect(std::string IP);
    bool Disconnect();

    void Poll();
    void HeartBeat();

    /* Queries */
    template <typename T>
    T GetVar(std::string varName);
    template <typename T>
    T SetVar(std::string varName);

    /* Other */
    void RegisterClient();
    void Update();  //  Per frame actions

    template<typename ret, typename... args>
    void AddAction(std::function<ret(args...)> script);
};

#endif