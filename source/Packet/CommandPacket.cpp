#include <Packet/CommandPacket.h>

CommandPacket::CommandPacket(const char* data) : APacket(E_PACKET::PACKET_COMMAND) { }

CommandPacket& CommandPacket::unpack(const std::vector<std::string>& data) {
    auto begin = data.begin() + 1;
    auto end = data.end();
    this->command = *begin;
    for(++begin; begin != end; ++begin)
        this->args.push(*begin);
    return *this;
}

const std::string& CommandPacket::getCommand() const {
    return this->command;
}