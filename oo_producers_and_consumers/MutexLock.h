#pragma once

#include <pthread.h>
#include "Noncopyable.h"
namespace wd
{
    class MutexLock : Noncopyable
    {
    public:
        MutexLock();
        ~MutexLock();

        void lock();
        void unlock();
        bool isLocking() const { return _isLocking; }
    
        pthread_mutex_t * getMutexLockPtr() { return & _mutex; }
    private:
        pthread_mutex_t _mutex;
        bool _isLocking;
    };
    
    class MutexLockGuard : Noncopyable
    {
    public:
        MutexLockGuard(MutexLock & mutex)
            : _mutex(mutex)
        {
            _mutex.lock();
        }

        ~MutexLockGuard()
        {
            _mutex.unlock();
        }
    private:
        MutexLock & _mutex;
    };
}

