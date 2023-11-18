#include "../include/Command.h"

Command::Command(const char* cmd, std::queue<const char*> args) : cmd(cmd, args) { }

Command::Command(const Command& other) : cmd(other.cmd) { }

const char* Command::getCmd() const {
    return cmd.cmd;
}

const std::queue<const char*>& Command::getArgs() const {
    return cmd.args;
}

