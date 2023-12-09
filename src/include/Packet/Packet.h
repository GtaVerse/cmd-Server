#ifndef PACKET_H_
#define PACKET_H_

#include <string>
#include <list>

enum E_PACKET {
    PACKET_COMMAND,
};

struct stCommandPacket {
    std::string command;
    std::list<std::string> args;
};

#endif
