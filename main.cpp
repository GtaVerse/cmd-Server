
#include "main.h"


int main()
{

    std::queue<const char*> args = queue<const char*>();
    args.push("-a");

    Command cmd = Command("/bin/ls", args);
    CommandProcessor cmdProc = CommandProcessor();
    cmdProc.addCommand(cmd);
    auto res = cmdProc.executeCommand();
    std::cout << res->output << std::endl;

    Server server;


}