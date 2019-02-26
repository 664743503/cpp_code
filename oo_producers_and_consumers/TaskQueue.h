#pragma once

#include <queue>
#include <iostream>
#include "MutexLock.h"
#include "Condition.h"

namespace wd
{
    using Type = uint32_t;

    class TaskQueue
    {
    public:
        TaskQueue(uint32_t queSize);
      
        bool full() const;
        bool empty() const;
        
        /*
         *运行在生产者线程
         */
        void push(Type & elem);
        /*
         *运行在消费者线程
         */
        Type pop();

    private:
        uint32_t _queSize;   
        std::queue<Type> _que;
        MutexLock _mutex;
        Condition _notFull;
        Condition _notEmpty;
    };
}
