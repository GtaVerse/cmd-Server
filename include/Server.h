#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
#include <utility>
#include <initializer_list>
#include <Client.h>
#include <ServerContext/AConfig.h>
#include <ServerContext/AConfigFile.h>

enum E_CLIENT_EVENT {
    CLIENT_CONNECT,
    CLIENT_DISCONNECT,
    CLIENT_MESSAGE
};

class Server : public AConfig, public AConfigFile {

    public:
        Server();
        ~Server() = default;

        void start();

        const type_port SERVER_PORT;
        const type_outfile SERVER_OUTFILE;

        const char* CLIENT_HOST;
        const bool LOGGING;
        const char* LOG_PATH;
        const int MAX_CONNECTION;

        using EVENT = void (*)(int, ...);
        EVENT onClientEvent;

    private:

        Server& addClient(int fd);
        Server& removeClient(int fd);


        inline void OnClientEvent(int event, ...);
        inline void OnClientConnect(int client_fd);
        inline void OnClientDisconnect(int client_fd);
        inline void OnClientMessage(int client_fd, const char* msg);

        int server_fd;
        fd_set sockets, read_fd;
        int max_fd;

        std::map<int, Client> clients;
};


#endif