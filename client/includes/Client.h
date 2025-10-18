#ifndef _CLIENT_H__
#define _CLIENT_H__

#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Client
{
private:
    unsigned long PID = -1; 

    const static std::string ip;
    std::vector<std::function<void()>> playerActions;
public:
    Client(std::string IP);

    /* Server Sync */
    bool Connect(std::string IP);
    bool Disconnect();

    void Poll();

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