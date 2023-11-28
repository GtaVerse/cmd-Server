#ifndef CS_H_
#define CS_H_

#define RELEASE 0


#if RELEASE == 0
    #include <iostream>
    #include <cstdio>
    //using namespace std;
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

#if RELEASE == 0
    #define LOGFD(...) { LOGF("%s:%s:%d: ", __FILE_NAME__, __FUNCTION__, __LINE__); LOGF(__VA_ARGS__); }
#else
    #define LOGFD(...) { }
#endif

#endif