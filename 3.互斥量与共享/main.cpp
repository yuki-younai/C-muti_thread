#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>

int shared_data = 0;
std::mutex mtx;
void func(int n) {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();
        shared_data++;        
        std::cout << "Thread " << n 
        << " increment shared_data to " << shared_data << std::endl;
        mtx.unlock();
    }
}
int main() {
    std::thread t1(func, 1);
    std::thread t2(func, 2);

    t1.join();
    t2.join();    
    std::cout << "Final shared_data = " << shared_data << std::endl;    
    return 0;
}