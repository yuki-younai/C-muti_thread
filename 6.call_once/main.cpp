#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>

static std::once_flag once;
class Log{
public:
Log(){}
Log(const Log& log)=delete;
Log& operator=(const Log& log)=delete;
static Log& GetInstance(){

    std::call_once(once,init);
    return *log;
}
static void init(){
    if(!log) log=new Log;
}
void PrintLog(std::string msg)
{
    std::cout<<msg<<std::endl;
}
private:
    static Log* log;
};
Log* Log::log =nullptr;


void print_erro()
{
    Log::GetInstance().PrintLog("erro");
}


int main()
{
    std::thread t1(print_erro);
    std::thread t2(print_erro);
    t1.join();
    t2.join();
    return 0;
}