#ifndef __ClientBaseTask_h__
#define __ClientBaseTask_h__

#pragma once
class ClientBaseTask : public ACE_Task_Base
{
public:
    ClientBaseTask();
    virtual ~ClientBaseTask();

    virtual void start()
    {
        activate();
    }

protected:
    ACE_Atomic_Op<ACE_Mutex, int> messageCount_;
    ACE_Atomic_Op<ACE_Mutex, int> messageCountInOneSecond_;
    ACE_Atomic_Op<ACE_Mutex, ACE_hrtime_t> totalElapsedTimeForSending_; // milli seconds
    ACE_Atomic_Op<ACE_Mutex, ACE_hrtime_t> totalElapsedTimeForSendingInOneSecond_; // milli seconds

    ACE_Atomic_Op<ACE_Mutex, int> averageMessageCountInOneSecond_;
    ACE_Atomic_Op<ACE_Mutex, ACE_hrtime_t> averageElapsedTimeForSendingInOneSecond_; // milli seconds
};


#endif /* __ClientBaseTask_h__ */

