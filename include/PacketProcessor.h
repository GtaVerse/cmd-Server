#ifndef PACKET_PROCESSOR_H_
#define PACKET_PROCESSOR_H_

#include <iostream>
#include <queue>
#include <set>
#include <Utility.h>
#include <CommandProcessor.h>
#include <Packet/CommandPacket.h>

class PacketProcessor {

    public:
        PacketProcessor();
        ~PacketProcessor() = default;

        void process();
        std::unique_ptr<APacket> unpack(const char* data);
        void addPacket(std::unique_ptr<APacket>& packet);

        void consumer(const CommandPacket& packet);

        class PacketProcessorException : public std::exception {
            public:
                PacketProcessorException(const char* msg) : msg(msg) {}
                const char* what() const throw() { return msg; }
            private:
                const char* msg;
        };

    private:
        inline E_PACKET getType(const char* id) const;

        std::set<E_PACKET> packet_types;
        std::queue<std::unique_ptr<APacket>> packets;

        static const CommandProcessor command_processor;
};

#endif