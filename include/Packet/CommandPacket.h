#ifndef COMMANDPACKET_H_
#define COMMANDPACKET_H_

#include "APacket.h"
#include <list>

class CommandPacket : public APacket {

    public:
        CommandPacket(const std::vector<std::string>& data);
        ~CommandPacket() = default;

        const std::string& getCommand() const;
        const std::list<std::string>& getArgs() const;

    private:
        std::string command;
        std::list<std::string> args;

};

#endif