#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
#include <list>

#include <CS.h>

struct st_cmd {
    //Todo: Fix this const char*
    const std::string& cmd;
    std::vector<const char*> args;

    st_cmd(const std::string& cmd, const std::list<std::string>& args) : cmd(cmd) {
        for(auto& arg : args)
            this->args.push_back(arg.c_str());
        this->args.push_back(nullptr);
    }
};

class Command
{
    public:
        Command(const std::string& command, const std::list<std::string>& args);
        Command(const Command& other);
        const std::string& getCmd() const;
        const std::vector<const char*>& getArgs() const;
        const st_cmd cmd;

};

#endif