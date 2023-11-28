#ifndef ACONFIG_H_
#define ACONFIG_H_

#include <Environment/ENV.CSPORT.h>
#include <Environment/ENV.CSOUTFILE.h>

class AConfig {

    protected:
        AConfig() = default;
        virtual ~AConfig() = default;

        const ENV_CSPORT env_port;
        const ENV_CSOUTFILE env_outfile;

        using type_port = ENV_CSPORT::env_type;
        using type_outfile = ENV_CSOUTFILE::env_type;
};



#endif
