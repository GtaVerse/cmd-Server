
#include <PacketProcessor.h>

void PacketProcessor::consumer(const CommandPacket& packet)
{
    LOGFD("PacketProcessor: Consuming CommandPacket\n");
    const Command command(packet.getCommand(), packet.getArgs());
    auto res = PacketProcessor::command_processor.runCommand(command);

    std::cout << "Output: " << res.get()->output << std::endl;

    this->packets.pop();
}

