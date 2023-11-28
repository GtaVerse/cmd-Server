#ifndef AENVIRONMENT_H_
#define AENVIRONMENT_H_

#include <cstdlib>
#include <cstring>
#include <type_traits>
#include <string>

template <typename T>
class AEnvironment
{
public:
    const T& getEnvValue() const {
        return env_value;
    }

protected:
    template <typename U = T>
    AEnvironment(const char* env_name, const T& default_value,
        typename std::enable_if<std::is_integral<U>::value>::type* = nullptr) {
        const char* env_value = std::getenv(env_name);
        this->env_value = env_value ? atoi(env_value) : default_value;
    }

    template <typename U = T>
    AEnvironment(const char* env_name, const T& default_value,
        typename std::enable_if<std::is_floating_point<U>::value>::type* = nullptr) {
        const char* env_value = std::getenv(env_name);
        this->env_value = env_value ? atof(env_value) : default_value;
    }

    template <typename U = T>
    AEnvironment(const char* env_name, const T& default_value,
        typename std::enable_if<std::is_same<U, std::string>::value>::type* = nullptr) {
        const char* env_value = std::getenv(env_name);
        this->env_value = env_value ? env_value : default_value;
    }

    template<typename U = T>
    AEnvironment(const char* env_name, const T& default_value,
        typename std::enable_if<std::is_same<U, bool>::value>::type* = nullptr) {
        const char* env_value = std::getenv(env_name);
        this->env_value = env_value ? (strcmp(env_value, "true") == 0) : default_value;
    }

    template<typename U = T>
    AEnvironment(const char* env_name, const T& default_value,
        typename std::enable_if<std::is_same<U, const char*>::value>::type* = nullptr) {
        const char* env_value = std::getenv(env_name);
        this->env_value = env_value ? env_value : default_value;
    }


    virtual ~AEnvironment() = default;

    T env_value;
};


#endif
