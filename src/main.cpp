
#include "main.h"

void OnEvent(int event, ...)
{

    va_list args;
    va_start(args, event);

    switch(event)
    {
        case CLIENT_CONNECT:
            std::cout << "Client connected" << std::endl;
            break;
        case CLIENT_DISCONNECT:
            std::cout << "Client disconnected" << std::endl;
            break;
        case CLIENT_MESSAGE:
            std::cout << "Client message: " << va_arg(args, int) << " " << va_arg(args, const char*) << std::endl;
            break;
    }

    va_end(args);
}

int main()
{

    //std::queue<const char*> args = queue<const char*>();
    //args.push("-a");

    //Command cmd = Command("/bin/ls", args);
    //CommandProcessor cmdProc = CommandProcessor();
    //cmdProc.addCommand(cmd);
    //auto res = cmdProc.executeCommand();
    //std::cout << res->output << std::endl;


    Server server;
    //server.onClientEvent = OnEvent;
    server.start();

}