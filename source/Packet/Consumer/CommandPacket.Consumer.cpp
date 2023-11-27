
#include <PacketProcessor.h>

void PacketProcessor::consumer(const CommandPacket& packet)
{
    std::cout << "Command: " << packet.getCommand() << " Args: ";
    for(auto& arg : packet.getArgs())
            std::cout << arg << " ";
    std::cout << std::endl;

    this->packets.pop();
    LOGFD("PacketProcessor: Consuming CommandPacket\n");
}

