#include <Server.h>

Server::Server() : SERVER_PORT(env_port.getEnvValue()), SERVER_OUTFILE(env_outfile.getEnvValue()) {

}

