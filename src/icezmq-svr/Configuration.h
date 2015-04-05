#ifndef __Configuration_h__
#define __Configuration_h__

#pragma once

class Configuration
{
public:
    Configuration();
    virtual ~Configuration();

    void init(int argc, ACE_TCHAR* argv[]);

    Ice::PropertiesPtr& properties()
    {
        return this->properties_;
    }

    bool isZmqTest()
    {
        return this->properties_->getPropertyWithDefault("type", "zmq").compare("zmq") == 0;
    }

    int getServerPortByInt()
    {
        return this->properties_->getPropertyAsIntWithDefault("port", 5555);
    }

    std::string getServerPort()
    {
        return this->properties_->getPropertyWithDefault("port", "5555");
    }

    int getPayloadSize()
    {
        return this->properties_->getPropertyAsIntWithDefault("size", 4096); // 4KB
    }

private:
    Ice::PropertiesPtr properties_;
};

typedef ACE_Singleton<Configuration, ACE_Null_Mutex> CONF;

#endif /* __Configuration_h__ */


