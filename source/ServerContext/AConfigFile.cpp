#include <ServerContext/AConfigFile.h>

AConfigFile::AConfigFile(const char* CONFIG_PATH) {
    if(this->isFileExist(CONFIG_PATH)) {
        this->file.load(CONFIG_PATH);
    }
    else
    {
        this->file["SERVER"]["client_host"] = "";
        this->file["SERVER"]["LOG"] = false;
        this->file["SERVER"]["LOG_PATH"] = "logs/";
        this->file["SERVER"]["MAX_CONNECTION"] = 5;
        this->file.save(CONFIG_PATH);
    }
}

bool AConfigFile::isFileExist(const char *path) {
    return stat(path, NULL) == 0;
}