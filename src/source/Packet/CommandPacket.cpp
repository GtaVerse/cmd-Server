#include <Packet/CommandPacket.h>

CommandPacket::CommandPacket(const std::vector<std::string>& data) : APacket(E_PACKET::PACKET_COMMAND) {
    auto begin = data.begin() + 1;
    auto end = data.end();
    this->packet.command = *begin;

    for(; begin != end - 1; ++begin)
        this->packet.args.push_back(*begin);

    //Todo: Fix this
    // This part copies the last element of the vector to a string and clears
    // the string of any trailing whitespace or newline characters
    // Make it while reading packet to avoid copying
    std::string last = *(end - 1);
    Utility::packet_clear_str(last);
    this->packet.args.push_back(last);
}

const std::string& CommandPacket::getCommand() const {
    return this->packet.command;
}

const std::list<std::string>& CommandPacket::getArgs() const {
    return this->packet.args;
}