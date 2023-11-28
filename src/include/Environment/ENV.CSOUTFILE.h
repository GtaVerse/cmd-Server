#pragma once

#include "AEnvironment.h"

class ENV_CSOUTFILE : public AEnvironment<const char*>
{
    public:
        ENV_CSOUTFILE();

        using env_type = const char*;
};