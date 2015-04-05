//
//  innoaus-ace-stopwatch.h
//  libinnoaus
//
//  Created by Leo An on 10/29/14.
//  Copyright (c) 2014 INNOAUS. All rights reserved.
//

#ifndef __libinnoaus__innoaus_ace_stopwatch__
#define __libinnoaus__innoaus_ace_stopwatch__

namespace innoaus {
namespace common {
namespace lib {
namespace utils {
    
    class StopWatchTimer
    {
    public:
        StopWatchTimer();
        virtual ~StopWatchTimer();
        
        void start();
        void stop();
        
        void display(const std::string& msg);
        
        ACE_High_Res_Timer&       getTimer();
        const ACE_Time_Value&     getElapsedMeasured();
        ACE_hrtime_t              getElapsedNanoseconds();
        ACE_hrtime_t              getElapsedMicroseconds();
        
    private:
        ACE_High_Res_Timer timer_;
        ACE_Time_Value     elapsedTimeMeasured_;
        ACE_hrtime_t       elapsedTimeNanoseconds_;
        ACE_hrtime_t       elapsedTimeMicroseconds_;
    };
    
    INNOAUS_INLINE
    StopWatchTimer::StopWatchTimer()
    {
    }
    
    INNOAUS_INLINE
    StopWatchTimer::~StopWatchTimer()
    {
        
    }
    
    INNOAUS_INLINE
    void StopWatchTimer::start()
    {
        this->timer_.start();
    }
    
    INNOAUS_INLINE
    void StopWatchTimer::stop()
    {
        this->timer_.stop();
        
        this->timer_.elapsed_time(this->elapsedTimeMeasured_);
        this->timer_.elapsed_time(this->elapsedTimeNanoseconds_);
        this->timer_.elapsed_microseconds(this->elapsedTimeMicroseconds_);
    }

    INNOAUS_INLINE
    void StopWatchTimer::display(const std::string& msg)
    {
        std::cout << msg << this->elapsedTimeMeasured_.sec() << "secs." << std::endl;
    }
    
    INNOAUS_INLINE
    ACE_High_Res_Timer& StopWatchTimer::getTimer()
    {
        return this->timer_;
    }
    
    INNOAUS_INLINE
    const ACE_Time_Value& StopWatchTimer::getElapsedMeasured()
    {
        return this->elapsedTimeMeasured_;
    }
    
    INNOAUS_INLINE
    ACE_hrtime_t StopWatchTimer::getElapsedNanoseconds()
    {
        return this->elapsedTimeNanoseconds_;
    }
    
    INNOAUS_INLINE
    ACE_hrtime_t StopWatchTimer::getElapsedMicroseconds()
    {
        return this->elapsedTimeMicroseconds_;
    }

    typedef ACE_Singleton<StopWatchTimer, ACE_Null_Mutex> STOPWATCH_TIMER;
    
} /* utils */
} /* lib */
} /* common */
} /* innoaus */

#endif /* defined(__libinnoaus__innoaus_ace_stopwatch__) */
