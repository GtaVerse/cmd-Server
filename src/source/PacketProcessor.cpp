#include "../include/PacketProcessor.h"

const CommandProcessor PacketProcessor::command_processor;

PacketProcessor::PacketProcessor()
{
    packet_types.insert(E_PACKET::PACKET_COMMAND);
}

void PacketProcessor::process()
{

    while(!packets.empty())
    {
        LOGF("PacketProcessor: Processing %lu packets\n", packets.size());
        switch (packets.front()->type)
        {
            case E_PACKET::PACKET_COMMAND:
                const CommandPacket& command_packet = static_cast<const CommandPacket&>(*packets.front());
                consumer(command_packet);
                break;
        }
    }
}


std::unique_ptr<APacket> PacketProcessor::unpack(const char* data)
{
    auto packet = Utility::str_split(data, ' ');
    try {
        auto packet_type = getType(packet[0].c_str());

        switch(packet_type)
        {
            case E_PACKET::PACKET_COMMAND:
                return std::make_unique<CommandPacket>(packet);
        }
    }
    catch(PacketProcessorException& e) {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
    return nullptr;
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