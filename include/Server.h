#ifndef SERVER_H_
#define SERVER_H_

#include <ServerContext/AConfig.h>

class Server : public AConfig {

public:
    Server();
    ~Server() = default;

    const type_port SERVER_PORT;
    const type_outfile SERVER_OUTFILE;
};


#endif