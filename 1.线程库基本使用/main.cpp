
#include <iostream>
#include <thread>
#include <string>
void printworld(std::string args)
{
    std::cout<<args<<std::endl;
    return;
}
int main()
{
    std::thread thread1(printworld,"hello wolld");
    if(thread1.joinable())
    {
        thread1.join();
    }
    thread1.detach();
    return 0;
}

