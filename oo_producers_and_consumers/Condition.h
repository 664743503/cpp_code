#pragma once

#include <pthread.h>
#include "Noncopyable.h"
#include "MutexLock.h"


namespace wd
{
    class Condition
    {
    public:
        Condition(MutexLock & mutex);
        ~Condition();

        void wait();
        void notify();
        void notifyAll();
    
    private:
        MutexLock & _mutex;
        pthread_cond_t _cond;
    };
}

