#ifndef COMMAND_H_
#define COMMAND_H_

#include <string.h>
#include <list>

struct st_cmd {
    const std::string& cmd;
    const std::list<const char*>& args;

    st_cmd(const std::string& cmd, const std::list<const char*>& args) : cmd(cmd), args(args) { }
};

class Command
{
    public:
        Command(const std::string& command, const std::list<const char*>& args);
        Command(const Command& other);
        const std::string& getCmd() const;
        const std::list<const char*>& getArgs() const;
        const st_cmd cmd;

};

#endif