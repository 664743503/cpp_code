#include "Thread.h"

namespace wd
{
    Thread::Thread()
        : _pthid(0)
        , _isrunning(false)
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
            //调用run方法用到了多态性质
            //这个run方法在基类中是没有实现的
            //当pthread执行run方法时，是调用的派生类的run方法
            pthread->run();
        return nullptr;
    }

    void Thread::join()
    {
        pthread_join(_pthid, nullptr);
    }
}
