#ifndef ACONFIGFILE_H_
#define ACONFIGFILE_H_

#include <sys/stat.h>
#include "../External/inicpp.h"

class AConfigFile {

    private:
        bool isFileExist(const char* path);

    protected:
        AConfigFile(const char* CONFIG_PATH);
        virtual ~AConfigFile() = default;

        ini::IniFile file;

};


#endif