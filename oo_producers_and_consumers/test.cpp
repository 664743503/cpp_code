#include <iostream>
#include <memory>
#include <unistd.h>
#include "Thread.h"
#include "TaskQueue.h"

using namespace wd;

//生产者类
class Producer: public wd::Thread
{
public:
    Producer(TaskQueue & taskQue)
        :_taskQue(taskQue)
    {
        std::cout << "Producer的构造函数" << std::endl; 
    }
    ~Producer() 
    {
        std::cout << "Producer的析构函数" << std::endl; 
    }
private:
    /*
     *生产数字
     */
    void run()
    {
        srand(clock());
        int cnt = 10;
        while(cnt--)
        {
            uint32_t number = rand() % 100;
            _taskQue.push(number);
            std::cout << "+++++++++Produce a number=" << number << std::endl;
            sleep(1);
        }
    }
private:
    TaskQueue & _taskQue;
};

//消费者类
class Consumer: public wd::Thread
{
public:
    Consumer(TaskQueue & taskQue)
        :_taskQue(taskQue)
    {
        std::cout << "Consumer的构造函数" << std::endl; 
    }
    ~Consumer() 
    {
        std::cout << "Consumer的析构函数" << std::endl; 
    }
private:
    /*
     *消费数字
     */
    void run()
    {
        srand(clock());
        int cnt = 10;
        while(cnt--)
        {
            uint32_t number = _taskQue.pop();
            std::cout << "-------Consume a number=" << number << std::endl;
            sleep(2);
        }
    }
private:
    TaskQueue & _taskQue;
};


int main()
{
    TaskQueue tq(3);
    std::unique_ptr<Thread> producer(new Producer(tq));
    std::unique_ptr<Thread> consumer(new Consumer(tq));
    producer->start();
    consumer->start();
    producer->join();
    consumer->join();
    return 0;
}

