#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
#include <utility>
#include <Client.h>
#include <ServerContext/AConfig.h>
#include <ServerContext/AConfigFile.h>

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



    private:

        Server& addClient(int fd);
        Server& removeClient(int fd);

        void OnClientConnect(int fd);
        void OnClientDisconnect(int fd);
        void OnClientMessage(int fd, const char* msg);

        int server_fd;
        fd_set sockets, read_fd;
        int max_fd;

        std::map<int, Client> clients;
};


#endif