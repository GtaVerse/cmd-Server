#include <Command.h>

Command::Command(const std::string& cmd, const std::list<const char*>& args) : cmd(cmd, args) { }

Command::Command(const Command& other) : cmd(other.cmd) { }

const std::string& Command::getCmd() const {
    return cmd.cmd;
}

const std::list<const char*>& Command::getArgs() const {
    return cmd.args;
}

