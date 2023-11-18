#include "../include/Environment/AEnvironment.h"

AEnvironment::AEnvironment(const char* env_name, const env_type& default_value)
{
    this->env_value = std::getenv(env_name);
    if(this->env_value == nullptr)
        this->env_value = default_value;
}

AEnvironment::~AEnvironment() { }

const AEnvironment::env_type& AEnvironment::getEnvValue() const
{
    return this->env_value;
}