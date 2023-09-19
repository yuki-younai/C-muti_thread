#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
#include<condition_variable>
#include<queue>


std::queue<int> q;
std::condition_variable q_cv;

std::mutex mtx;
void Producer()
{
    for(int i=0;i<10;i++)
    {
        std::unique_lock<std::mutex>  lock(mtx);
        q.push(i);
        q_cv.notify_one();
        std::cout<<"task"<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }

}
void Consumer()
{
    while(1){
        std::unique_lock<std::mutex>  lock(mtx);
        q_cv.wait(lock,[](){return !q.empty();});
        int value=q.front();
        q.pop(); 
        std::cout<<"consumer"<<value<<std::endl;
    }
}

int main()
{
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t1.join();
    t2.join();
    return 0;
}




