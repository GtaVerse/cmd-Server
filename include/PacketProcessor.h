#ifndef PACKET_PROCESSOR_H_
#define PACKET_PROCESSOR_H_

#include <set>
#include <Utility.h>
#include <Packet/CommandPacket.h>

class PacketProcessor {

    public:
        PacketProcessor();
        ~PacketProcessor() = default;

        std::unique_ptr<APacket> unpack(const char* data);

        class PacketProcessorException : public std::exception {
            public:
                PacketProcessorException(const char* msg) : msg(msg) {}
                const char* what() const throw() { return msg; }
            private:
                const char* msg;
        };

    private:
        inline E_PACKET getType(const char* id);

        std::set<E_PACKET> packet_types;
};

#endif