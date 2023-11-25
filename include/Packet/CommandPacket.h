#ifndef COMMANDPACKET_H_
#define COMMANDPACKET_H_

#include "APacket.h"
#include <queue>

class CommandPacket : public APacket {

    public:
        CommandPacket(const std::vector<std::string>& data);
        ~CommandPacket() = default;

        const std::string& getCommand() const;
        const std::string& getArgs() const;

    private:
        std::string command;
        std::queue<std::string> args;

};

#endif