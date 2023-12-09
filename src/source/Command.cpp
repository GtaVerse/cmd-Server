#include <Command.h>

Command::Command(const std::string& cmd, const std::list<std::string>& args) : cmd(cmd, args) { }

Command::Command(const Command& other) : cmd(other.cmd) { }

const std::string& Command::getCmd() const {
    return cmd.cmd;
}

const std::vector<const char*>& Command::getArgs() const {
    return cmd.args;
}

