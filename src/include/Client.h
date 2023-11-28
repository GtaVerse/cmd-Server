#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <unistd.h>

class Client {
    public:
        Client();
        Client(int fd);
        ~Client() = default;

        const std::string& getMessage() const;
        void addMessage(const std::string& msg);
        void clearMessage();

        const int fd;

    private:
        std::string msg;
};

#endif