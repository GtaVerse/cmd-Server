#include <Packet/CommandPacket.h>

CommandPacket::CommandPacket(const std::vector<std::string>& data) : APacket(E_PACKET::PACKET_COMMAND) {
    auto begin = data.begin() + 1;
    auto end = data.end();
    this->command = *begin;
    for(++begin; begin != end; ++begin)
        this->args.push_back(begin->c_str());
    this->args.push_back(nullptr);
}

const std::string& CommandPacket::getCommand() const {
    return this->command;
}

const std::list<const char*>& CommandPacket::getArgs() const {
    return this->args;
}