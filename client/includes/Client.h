#ifndef _CLIENT_H__
#define _CLIENT_H__

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "SocketHandler.h"

using ClientAttributes = std::unordered_map<std::string, std::string>;
const char del = ',';

class Client
{
private:
    std::string UUID = ""; 
    std::vector<std::function<void()>> playerActions;

    ClientAttributes attribs;

    std::pair<std::string, std::string> ParsePacket(std::string dictionaryPair);

public:
    Client(std::string IP);

    /* Server Sync */
    bool Connect(std::string IP);
    bool Disconnect();

    /* Queries */
    template <typename T>
    T GetVar(std::string varName);
    template <typename T>
    T SetVar(std::string varName);

    /* Other */
    void Update();  //  Per frame actions
    void Sync();    //  Syncs updates with server (send and retrieve)

    template<typename ret, typename... args>
    void AddAction(std::function<ret(args...)> script);
    void AddDictElement(std::string key, std::string value);

    void DictPrintDebug();
};

#endif