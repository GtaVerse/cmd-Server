#include <Packet/APacket.h>

APacket::APacket(E_PACKET type) : type(type) { }

APacket::~APacket() {
    LOGF("APacket: Destroying packet type %d\n", type);
}
