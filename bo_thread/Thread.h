#pragma once

#include <pthread.h>
#include <functional>

namespace wd{

    class Thread
    {
    public:
        Thread(std::function<void()> && cb);        //右值引用传递参数
        ~Thread();
    
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
         * 线程执行体
         */
        static void * func(void * arg);
    private:
        pthread_t _pthid;
        bool _isrunning;
        std::function<void()> _cb;
    };
}
