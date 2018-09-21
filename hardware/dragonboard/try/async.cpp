#include <chrono>
#include <iostream>
#include <future>

void timer() {
    for(int i=0;i<10;++i)
    {
        std::cout << (10-i) << '\n';
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    }
}
int main ()
{
    auto future = std::async(timer);
    std::cout << "test\n";
    auto future2 = std::async(timer);
    std::cout << "test2\n";
}
