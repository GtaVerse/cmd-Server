#include "../../include/Packet/CommandPacket.h"

CommandPacket::CommandPacket(const char* data) : APacket(E_PACKET::COMMAND) { }

CommandPacket& CommandPacket::unpack(const char* data) {
   auto command = std::move(Utility::str_split(data, ' '));
   this->command = command[0];
   for(const auto& arg : command)
         this->args.push(arg);

    return *this;
}