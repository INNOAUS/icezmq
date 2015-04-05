#ifndef __IceClient_h__
#define __IceClient_h__

#pragma once

#include "ClientBaseTask.h"

class IceClient : public ClientBaseTask
{
public:
    IceClient();
    virtual ~IceClient();

protected:
    virtual int svc();
};

typedef ACE_Singleton<IceClient, ACE_Null_Mutex> ICECLIENT;

#endif /* __IceClient_h__ */

