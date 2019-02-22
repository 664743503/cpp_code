#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>

class Task
{
public:
    void process()
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

void process2()
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

int main()
{
    Task task;
    //std::unique_ptr<wd::Thread> thread1(new wd::Thread(std::bind(&Task::process, &task)));
    std::unique_ptr<wd::Thread> thread1(new wd::Thread(std::bind(&Task::process, task)));
    std::unique_ptr<wd::Thread> thread2(new wd::Thread(process2));
    thread1->start();
    thread2->start();
    thread1->join();
    thread2->join();
    return 0;
}
