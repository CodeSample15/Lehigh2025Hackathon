#ifndef _CLIENT_H__
#define _CLIENT_H__

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>

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

    std::map<std::string, std::string> variables;
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

    void init(); // pull all server config from interwebs
    void sync(); // sync changes to/from server

    template<typename ret, typename... args>
    void AddAction(std::function<ret(args...)> script);
};

#endif