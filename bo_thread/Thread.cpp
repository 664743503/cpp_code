#include "Thread.h"

namespace wd
{
    Thread::Thread(std::function<void()> && cb)
        : _pthid(0)
        , _isrunning(false)
        , _cb(std::move(cb))
    {}

    Thread::~Thread()
    {
        if(_isrunning)
        {
            pthread_detach(_pthid);
        }
    }

    void Thread::start()
    {
        pthread_create(&_pthid, nullptr, func, this);
        _isrunning = true;
    }

    void * Thread::func(void * arg)
    {
        Thread * pthread = static_cast<Thread*>(arg);
        if(pthread)
            pthread->_cb();
        return nullptr;
    }

    void Thread::join()
    {
        pthread_join(_pthid, nullptr);
    }
}
