#ifndef SERVER_H_
#define SERVER_H_

#include <ServerContext/AConfig.h>
#include <ServerContext/AConfigFile.h>

class Server : public AConfig, public AConfigFile {

public:
    Server();
    ~Server() = default;

    const type_port SERVER_PORT;
    const type_outfile SERVER_OUTFILE;

    const char* CLIENT_HOST;
    const bool LOGGING;
    const char* LOG_PATH;
};


#endif