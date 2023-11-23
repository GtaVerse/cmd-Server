#include <Server.h>

Server::Server() : AConfigFile("config.ini"),
                onClientEvent(nullptr),
                SERVER_PORT(env_port.getEnvValue()),
                SERVER_OUTFILE(env_outfile.getEnvValue()),
                CLIENT_HOST(file["SERVER"]["client_host"].as<const char*>()),
                LOGGING(file["SERVER"]["LOG"].as<bool>()),
                LOG_PATH(file["SERVER"]["LOG_PATH"].as<const char*>()),
                MAX_CONNECTION(file["SERVER"]["MAX_CONNECTION"].as<int>()),
                MAX_MESSAGE(file["SERVER"]["MAX_MESSAGE"].as<int>())
                {
    struct sockaddr_in serverAddr;
    if((this->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        throw std::runtime_error("Server: socket failed");

    LOG("Server: socket created");
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(this->SERVER_PORT);
    serverAddr.sin_addr.s_addr = strlen(this->CLIENT_HOST) == 0 ? INADDR_ANY : inet_addr(this->CLIENT_HOST);

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    if(bind(server_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        throw std::runtime_error("Server: bind failed");

    //if(fcntl(server_fd, F_SETFL, O_NONBLOCK) < 0)
        //std::cout << "fcntl failed" << std::endl;

    if(listen(server_fd, MAX_CONNECTION) < 0)
        throw std::runtime_error("Server: listen failed");

    FD_ZERO(&this->sockets);
    FD_SET(this->server_fd, &sockets);
    this->max_fd = this->server_fd;

    std::cout << "Server listening on port " << this->SERVER_PORT << std::endl;
}


void Server::start() {

    while(true)
    {
        for(int fd = 0; fd <= this->max_fd; fd++)
        {
            this->read_fd = this->sockets;
            int ret = select(this->max_fd + 1, &this->read_fd, NULL, NULL, NULL);
            if(ret < 0)
                continue;
            if(FD_ISSET(fd, &this->read_fd))
            {
                if(fd == this->server_fd)
                {
                    struct sockaddr_in clientAddr;
                    socklen_t clientAddrLen = sizeof(clientAddr);
                    int client_fd = accept(this->server_fd, (struct sockaddr *)&clientAddr, &clientAddrLen);

                    if(client_fd < 0) {
                        std::cout << "accept failed" << std::endl;
                        continue;
                    }

                   this->OnClientEvent(CLIENT_CONNECT, client_fd);
                }
                else
                {
                    char buffer[this->MAX_MESSAGE + 1];
                    int len = read(fd, buffer, sizeof(buffer));

                    if(len == 0)
                        this->OnClientEvent(CLIENT_DISCONNECT, fd);
                    else if(len == 10)
                        this->clients[fd].addMessage(buffer);
                    else
                    {
                        buffer[len] = '\0';
                        this->OnClientEvent(CLIENT_MESSAGE, fd, buffer);
                    }
                }
            }

        }
    }

}

void Server::OnClientEvent(int event, ...) {

    int fd;
    va_list arg;
    va_start(arg, event);

    switch(static_cast<E_CLIENT_EVENT>(event)) {
        case CLIENT_CONNECT:
            fd = va_arg(arg, int);
            this->OnClientConnect(fd);
            break;
        case CLIENT_DISCONNECT:
            fd = va_arg(arg, int);
            this->OnClientDisconnect(fd);
            break;
        case CLIENT_MESSAGE:
            fd = va_arg(arg, int);
            const char* msg = va_arg(arg, const char*);
            this->OnClientMessage(fd, msg);
            break;
    }

    va_end(arg);
}

void Server::OnClientConnect(int fd) {
    FD_SET(fd, &this->sockets);
    fcntl(fd, F_SETFL, O_NONBLOCK);
    this->addClient(fd);
    if(this->onClientEvent != nullptr)
        this->onClientEvent(CLIENT_CONNECT, fd);
}

void Server::OnClientDisconnect(int fd) {
    FD_CLR(fd, &this->sockets);
    fcntl(fd, F_SETFL, 0);
    this->removeClient(fd);
}

void Server::OnClientMessage(int fd, const char* msg) {
    this->clients[fd].addMessage(msg);
    if(this->onClientEvent != nullptr)
        this->onClientEvent(CLIENT_MESSAGE, fd, this->clients[fd].getMessage().c_str());
    this->clients[fd].clearMessage();
}

Server& Server::addClient(int fd) {
    this->clients.insert(std::make_pair(fd, Client(fd)));
    if(fd > this->max_fd)
        this->max_fd = fd;
    if(this->onClientEvent != nullptr)
        this->onClientEvent(CLIENT_DISCONNECT, fd);
    return *this;
}

Server& Server::removeClient(int fd) {
    this->clients.erase(fd);
    close(fd);
    if(fd == this->max_fd)
        this->max_fd = server_fd > this->clients.rbegin()->first ? server_fd : this->clients.rbegin()->first;
    return *this;
}
