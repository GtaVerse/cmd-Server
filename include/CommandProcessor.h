#ifndef COMMANDPROCESSOR_H_
#define COMMANDPROCESSOR_H_

#include "Command.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <memory>

struct st_commandResult {
    int exitCode;
    std::string output;

    st_commandResult(int exitCode, std::string output) : exitCode(exitCode), output(output) { }
};

class CommandProcessor {

    public:
        void addCommand(const Command& cmd);
        bool delCommand(const char* cmd);
        std::unique_ptr<st_commandResult> executeCommand();
        //void executeCommand(const char* cmd);

    private:
        inline int findCommandIndex(const char* cmd);
        inline std::unique_ptr<st_commandResult> runCommand(const Command& cmd);

        std::vector<Command> commands;
};


#endif
