#ifndef COMMANDPACKET_H_
#define COMMANDPACKET_H_

#include "APacket.h"
#include <queue>

class CommandPacket : public APacket {

    public:
        CommandPacket(const char* data);
        ~CommandPacket() = default;
        CommandPacket& unpack(const char* data) override;

        const std::string& getCommand() const;
        const std::string& getArgs() const;

    private:
        std::string command;
        std::queue<std::string> args;

};

#endif