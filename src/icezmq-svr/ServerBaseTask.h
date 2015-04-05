#ifndef __ServerBaseTask_h__
#define __ServerBaseTask_h__

#pragma once
class ServerBaseTask : public ACE_Task_Base
{
public:
    ServerBaseTask();
    virtual ~ServerBaseTask();

    virtual void start()
    {
        activate();
    }

protected:
    ACE_Atomic_Op<ACE_Mutex, int> messageCount_;
    ACE_Atomic_Op<ACE_Mutex, ACE_hrtime_t> totalElapsedTimeForReceiving_; // milli seconds
};


#endif /* __ServerBaseTask_h__ */

