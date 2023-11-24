#include "../include/PacketProcessor.h"

PacketProcessor::PacketProcessor()
{
    packet_types.insert(E_PACKET::PACKET_COMMAND);
}

void PacketProcessor::process()
{

    while(!packets.empty())
    {
        auto &packet = packets.front();
        switch (packet->type) {
            case E_PACKET::PACKET_COMMAND:
                std::cout << "CommandPacket: " << static_cast<CommandPacket *>(packet.get())->getCommand() << std::endl;
                break;
            default:
                break;
        }
        packets.pop();
    }
}


std::unique_ptr<APacket> PacketProcessor::unpack(const char* data)
{
    auto packet = std::move(Utility::str_split(data, ' '));

    try {
        auto packet_type = getType(packet[0].c_str());

        switch(packet_type)
        {
            case E_PACKET::PACKET_COMMAND:

                return std::make_unique<CommandPacket>(CommandPacket(data).unpack(packet));
            default:
                return nullptr;
        }
    }
    catch(PacketProcessorException& e) {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}

void PacketProcessor::addPacket(std::unique_ptr<APacket>& packet)
{
    packets.push(std::move(packet));
}

E_PACKET PacketProcessor::getType(const char* id) const
{
    try {
        auto packet_type = static_cast<E_PACKET>(std::stoi(id));
        auto it = packet_types.find(packet_type);
        if(it == packet_types.end())
            throw PacketProcessorException("PacketProcessor: Invalid packet type");
        return packet_type;
    }
    catch(std::invalid_argument& e) {
        throw PacketProcessorException("PacketProcessor: Parse error");
    }
}