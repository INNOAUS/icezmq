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

    std::string getServerAddress()
    {
        return this->properties_->getPropertyWithDefault("host", "localhost");
    }

    int getServerPort()
    {
        return this->properties_->getPropertyAsIntWithDefault("port", 5555);
    }

    int getPayloadSize()
    {
        return this->properties_->getPropertyAsIntWithDefault("size", 4); // 4Bytes
    }

    int getLoopCount()
    {
        return this->properties_->getPropertyAsIntWithDefault("loop", 10);
    }

private:
    Ice::PropertiesPtr properties_;
};

typedef ACE_Singleton<Configuration, ACE_Null_Mutex> CONF;

#endif /* __Configuration_h__ */


