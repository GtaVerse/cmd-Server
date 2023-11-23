#ifndef CS_H_
#define CS_H_

#define RELEASE 0

#if RELEASE
    #include <iostream>
    using namespace std;
#endif

#if RELEASE == 0
    #define LOG(msg) \
        { \
            [](const char* message) { std::cout << message << std::endl; }(msg); \
        }
#else
    #define LOG(msg) { }
#endif

#endif