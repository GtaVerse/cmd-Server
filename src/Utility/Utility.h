#ifndef UTILITY_H_
#define UTILITY_H_

#include <vector>
#include <string>

class Utility {

    public:
        static std::vector<std::string> str_split(const char* str, char c) {
            std::vector<std::string> result;
            const char* start = str;

            while(*str)
            {
                if(*str == c)
                {
                    result.push_back(std::string(start, str));
                    start = str + 1;
                }
                str++;
            }
            if(start < str)
                result.push_back(std::string(start, str));

            return result;
        }

        /*
        * Summary:
        * Removes the last character of a string if it is a newline character.
        */
        static void packet_clear_str(std::string& packet) {
            auto last = packet.size() - 1;
            if(packet[last] == '\n')
                packet = packet.substr(0, last);
        }
};



#endif