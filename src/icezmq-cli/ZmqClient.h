#ifndef __ZmqClient_h__
#define __ZmqClient_h__

#pragma once

#include "ClientBaseTask.h"

class ZmqClient : public ClientBaseTask
{
public:
    ZmqClient();
    virtual ~ZmqClient();

protected:
    virtual int svc();
};

typedef ACE_Singleton<ZmqClient, ACE_Null_Mutex> ZMQCLIENT;

#endif /* __ZmqClient_h__ */

