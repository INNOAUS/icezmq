#ifndef __IceServer_h__
#define __IceServer_h__

#pragma once

#include "ServerBaseTask.h"

class IceServer : public ServerBaseTask
{
public:
    friend class ITesterImpl;

    IceServer();
    virtual ~IceServer();

    void start()
    {
        ServerBaseTask::start();
    }

protected:
    virtual int svc();
};

typedef ACE_Singleton<IceServer, ACE_Null_Mutex> ICE_SERVER;

#endif /* __IceServer_h__ */

