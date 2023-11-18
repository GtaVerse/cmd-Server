#ifndef AENVIRONMENT_H_
#define AENVIRONMENT_H_


template <typename T>
class AEnvironment
{
    public:
        typedef T env_type;
        const env_type& getEnvValue() const;


    protected:
        AEnvironment(const char* env_name);
        virtual ~AEnvironment();

        T env_value;

};


#endif