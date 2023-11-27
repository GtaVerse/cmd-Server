#ifndef COMMANDPROCESSOR_H_
#define COMMANDPROCESSOR_H_

#include "Command.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <memory>

struct st_commandResult {
    int exitCode;
    std::string output;

    st_commandResult(int exitCode, std::string output) : exitCode(exitCode), output(output) { }
};

class CommandProcessor {

    public:
        CommandProcessor() = default;
        ~CommandProcessor() = default;
        CommandProcessor(CommandProcessor&& other) = default;

        std::unique_ptr<st_commandResult> runCommand(Command cmd);

};


#endif
