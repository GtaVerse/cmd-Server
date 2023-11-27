#include <CommandProcessor.h>

std::unique_ptr<st_commandResult> CommandProcessor::runCommand(const Command& cmd) const {


    int pipefd[2];

    if (pipe(pipefd) == -1)
        return std::make_unique<st_commandResult>(-1, "Error: pipe failed");

    auto childPid = fork();

    if (childPid == -1)
        return std::make_unique<st_commandResult>(-1, "Error: fork failed");

    if (childPid == 0)
    {
        dup2(pipefd[1], STDOUT_FILENO);
        //close(pipefd[0]);

        if (execv(cmd.getCmd().c_str(), const_cast<char* const*>(&cmd.getArgs().front())) == -1)
            exit(EXIT_FAILURE);
        exit(EXIT_FAILURE);
    } else
    {
        int status;
        waitpid(childPid, &status, 0);

        if(WIFEXITED(status) && WEXITSTATUS(status) != 0)
            return std::make_unique<st_commandResult>(WEXITSTATUS(status), "Error: command failed");

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