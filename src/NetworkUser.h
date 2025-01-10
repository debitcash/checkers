#ifndef NETWORKUSER_H
#define NETWORKUSER_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Board.h"
#include "User.h"

// NetworkUser class represents a person using a terminal over network in PvP mode
class NetworkUser : public User{
protected:
    // address of server socket
    static sockaddr_in serverAddress;
    // client and server socket file descriptors
    static int serverSocket, clientSocket;
    // stores move provided by get move
    static std::string serverName, clientName;

public:
    NetworkUser();
    ~NetworkUser();
    
    void checkConnection();
};

std::string NetworkUser::serverName = "";
std::string NetworkUser::clientName = "";
//std::string NetworkUser::lastProvidedMove = "";

int NetworkUser::serverSocket = 0;
int NetworkUser::clientSocket = 0;

sockaddr_in NetworkUser::serverAddress = {};

#endif //NETWORKUSER_H