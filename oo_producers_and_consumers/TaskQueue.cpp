#include "TaskQueue.h"

using namespace wd;

TaskQueue::TaskQueue(uint32_t queSize)
    :_queSize(queSize)
     ,_mutex()
     ,_notFull(_mutex)
     ,_notEmpty(_mutex)
{}

bool TaskQueue::full() const 
{
    return _queSize == _que.size();
}

bool TaskQueue::empty() const 
{
    return 0 == _que.size();
}

void TaskQueue::push(Type & elem)
{
    MutexLockGuard autoLock(_mutex);
    while(full())       //while防止被异常唤醒
    {
        _notFull.wait();
    }
    _que.push(elem);
    _notEmpty.notify();
}

Type TaskQueue::pop()
{
    MutexLockGuard autoLock(_mutex);
    while(empty())
    {
        _notEmpty.wait();
    }
    Type tmp = _que.front();
    _que.pop();
    _notFull.notify();
    return tmp;
}
