#ifndef __ZServer_h__
#define __ZServer_h__

#pragma once

#include "ServerBaseTask.h"

class ZmqServer : public ServerBaseTask
{
public:
    ZmqServer()
    {
        this->context_ = 0;
        this->socket_ = 0;
    }

    void start()
    {
        assert(this->context_ == 0 && this->socket_ == 0);

        this->context_ = new zmq::context_t(1);
        this->socket_ = new zmq::socket_t(*this->context_, ZMQ_REP);

        ServerBaseTask::start();
    }

protected:
    virtual int svc();

private:
    zmq::context_t* context_;
    zmq::socket_t* socket_;
};

typedef ACE_Singleton<ZmqServer, ACE_Null_Mutex> ZMQ;

#endif /* __ZServer_h__ */

