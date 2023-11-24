#ifndef CS_H_
#define CS_H_

#define RELEASE 0

#if RELEASE
    #include <iostream>
    #include <cstdio>
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

#if RELEASE == 0
    #define LOGF(...) { printf(__VA_ARGS__); }
    #else
        #define LOGF(...) { }
#endif

#endif