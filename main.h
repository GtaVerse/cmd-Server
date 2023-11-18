#ifndef MAIN_H_
#define MAIN_H_

#include "include/Command.h"
#include "include/CommandProcessor.h"

#define RELEASE 0

#if !RELEASE
    #include <iostream>
    using namespace std;
#endif


#endif