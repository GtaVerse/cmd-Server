#ifndef APACKET_H_
#define APACKET_H_

#include <Packet/Packet.h>
#include <Utility.h>

class APacket {

    public:
        APacket(E_PACKET type);
        virtual ~APacket() = default;
        virtual APacket& unpack(const std::vector<std::string>& data) = 0;

        const E_PACKET type;


};

#endif