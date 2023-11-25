
#include <PacketProcessor.h>

void PacketProcessor::consumer(const CommandPacket& packet)
{

    this->packets.pop();
    LOGFD("PacketProcessor: Consuming CommandPacket\n");
}

