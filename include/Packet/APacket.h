#ifndef APACKET_H_
#define APACKET_H_

#include "Packet.h"
#include <Utility.h>

class APacket {

    public:
        APacket(E_PACKET type);
        virtual ~APacket() = default;
        virtual void unpack(const char* data) = 0;

        const E_PACKET type;


};

#endif