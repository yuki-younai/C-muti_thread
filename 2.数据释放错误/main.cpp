#include <iostream>
#include <thread>
#include <string>
#include <memory>

//1. 传递临时变量的问题
// int main() {
//     int x = 1; // 将变量复制到一个持久的对象中
//     std::thread t(foo, std::ref(x)); // 将变量的引用传递给线程
//     t.join();
//     std::cout<<x<<std::endl;
//     return 0;
// }
//2.2. 传递指针或引用指向局部变量的问题
// int main() {
//     int x = 1;
//     std::thread t(foo, &x); // 传递指向局部变量的指针
//     t.join();
//     //std::cout<<x<<std::endl;
//     return 0;
// }
//3. 传递指针或引用指向已释放的内存的问题：
// int main() {
//     std::shared_ptr<int> obj = std::make_shared<int>();
//     std::thread t(foo, obj); // 传递已经释放的内存
//     t.join();
//     return 0;
// }

void foo(int* ptr) {
    std::cout << *ptr << std::endl;
    delete ptr; // 在使用完指针后，需要手动释放内存
}
int main() {
    int* ptr = new int(1); // 在堆上分配一个整数变量
    std::thread t(foo, ptr); // 将指针传递给线程
    t.join();
    return 0;
}