#pragma once

#include <pthread.h>
#include "Noncopyable.h"

namespace wd{

    class Thread : Noncopyable
    {
    public:
        Thread();
        virtual ~Thread();
    
        /*
         * 线程开始
         */
        void start();
        /*
         * 线程等待
         */
        void join();
        /*
         * 获取线程状态
         */
        bool isRunning()
        {
            return _isrunning;
        }
    private:
        /*
         * 线程真正要执行的任务
         */
        virtual void run() = 0;
        
        /*
         * 线程执行体
         */
        static void * func(void * arg);
    private:
        pthread_t _pthid;
        bool _isrunning;
    };
}
