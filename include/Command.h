#ifndef COMMAND_H_
#define COMMAND_H_

#include <queue>

struct st_cmd {
    const char *cmd;
    std::queue<const char*> args;

    st_cmd(const char* cmd, std::queue<const char*> args) {
        this->cmd = cmd;
        if(strcmp(cmd, args.front()) != 0) {
            std::queue<const char*> new_args;
            new_args.push(const_cast<char*>(cmd));
            while(!args.empty()) {
                new_args.push(args.front());
                args.pop();
            }
            this->args = new_args;
        }
        if(args.back() != nullptr)
            this->args.push(nullptr);

    }
};

class Command
{
    public:
        Command(const char* cmd, std::queue<const char*> args);
        Command(const Command& other);
        const char* getCmd() const;
        const std::queue<const char*>& getArgs() const;
        const st_cmd cmd;

};

#endif