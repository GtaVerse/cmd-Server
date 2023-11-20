#pragma once


//#include <Environment/AEnvironment.h>
#include "AEnvironment.h"

class ENV_CSPORT : public AEnvironment<int>
{
public:
    ENV_CSPORT();

    using env_type = int;
};

