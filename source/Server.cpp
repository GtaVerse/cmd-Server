#include <Server.h>

Server::Server() : AConfigFile("config.ini"),
                SERVER_PORT(env_port.getEnvValue()),
                SERVER_OUTFILE(env_outfile.getEnvValue()),
                CLIENT_HOST(file["SERVER"]["client_host"].as<const char*>()),
                LOGGING(file["SERVER"]["LOG"].as<bool>()),
                LOG_PATH(file["SERVER"]["LOG_PATH"].as<const char*>()) {

}

