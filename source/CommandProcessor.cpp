#include <CommandProcessor.h>

void CommandProcessor::addCommand(const Command &cmd) {
    commands.push_back(cmd);
}

bool CommandProcessor::delCommand(const char *cmd) {
    auto index = findCommandIndex(cmd);
    if (index == -1)
        return false;
    std::vector<Command> new_commands;
    for(int i = commands.size() - 1; i >= 0; i--) {
        if (i != index)
            new_commands.push_back(commands[i]);
    }
    this->commands = std::move(new_commands);
    return true;
}

std::unique_ptr<st_commandResult> CommandProcessor::executeCommand() {
    int index = commands.size() - 1;
    if (index == -1)
        return std::make_unique<st_commandResult>(-1, "Error: no commands");
    auto cmd = commands[index];
    auto cmd_res = this->runCommand(cmd);
    //TODO: impl event
    return cmd_res;
}

int CommandProcessor::findCommandIndex(const char *cmd) {
    for(int i = commands.size() - 1; i >= 0; i--) {
        if (strcmp(commands[i].getCmd(), cmd) == 0)
            return i;
    }
    return -1;
}

std::unique_ptr<st_commandResult> CommandProcessor::runCommand(const Command &cmd) {

    int pipefd[2];

    if (pipe(pipefd) == -1)
        return std::make_unique<st_commandResult>(-1, "Error: pipe failed");

    auto childPid = fork();

    if (childPid == -1)
        return std::make_unique<st_commandResult>(-1, "Error: fork failed");

    if (childPid == 0)
    {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        if (execv(cmd.getCmd(), const_cast<char* const*>(&cmd.getArgs().front())) == -1)
            return std::make_unique<st_commandResult>(-1, "Error: execv failed");
    } else
    {
        int status;
        waitpid(childPid, &status, 0);
        close(pipefd[1]);

        std::string res;
        char c;
        while (read(pipefd[0], &c, 1) > 0)
            res += c;
        close(pipefd[0]);
        return std::make_unique<st_commandResult>(status, res);
    }
    return std::make_unique<st_commandResult>(-1, "Error: unknown error");
}