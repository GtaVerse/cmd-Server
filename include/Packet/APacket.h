#ifndef APACKET_H_
#define APACKET_H_

#include <Packet/Packet.h>
#include <Utility.h>
#include <CS.h>

class APacket {

    public:
        const E_PACKET type;
        virtual ~APacket();

    protected:
        APacket(E_PACKET type);

};

#endif