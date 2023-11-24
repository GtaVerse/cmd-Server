#include "../include/PacketProcessor.h"

PacketProcessor::PacketProcessor()
{
    packet_types.insert(E_PACKET::PACKET_COMMAND);
}


std::unique_ptr<APacket> PacketProcessor::unpack(const char* data)
{
    auto packet = std::move(Utility::str_split(data, ' '));
    auto packet_type = getType(packet[0].c_str());

    switch(packet_type)
    {
        case E_PACKET::PACKET_COMMAND:
            return std::make_unique<CommandPacket>(data);
        default:
            return nullptr;
    }
}

E_PACKET PacketProcessor::getType(const char* id)
{
    try {
        auto packet_type = static_cast<E_PACKET>(std::stoi(id));
        auto it = packet_types.find(packet_type);
        if(it == packet_types.end())
            throw PacketProcessorException("Invalid packet type");
    }
    catch(std::invalid_argument& e) {
        throw PacketProcessorException("Parse error");
    }
    catch(std::exception& e) {
        throw PacketProcessorException(e.what());
    }
}