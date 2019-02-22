#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>

class MyThread : public wd::Thread
{
public:
    MyThread() { std::cout << "MyThread的构造函数" << std::endl; }
    ~MyThread() { std::cout << "MyThread的析构函数" << std::endl; }
private:
    /*
     * 线程执行操作需求的方法
     */
    void run()
    {
        srand(clock());
        int cnt = 5;
        while(cnt--)
        {
            int number = rand() % 100;
            std::cout << "number=" << number << std::endl;
            sleep(1);
        }
    }
};

int main()
{
    std::unique_ptr<wd::Thread> thread1(new MyThread);
    std::unique_ptr<wd::Thread> thread2(new MyThread);
    thread1->start();
    thread2->start();
    thread1->join();
    thread2->join();
    return 0;
}

