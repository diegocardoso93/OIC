#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

class Timer
{
    thread th;
    bool running = false;

public:
    typedef chrono::microseconds Interval;
    typedef std::function<void(void)> Timeout;

    void start(const Interval &interval,
               const Timeout &timeout)
    {
        running = true;

        th = thread([=]()
        {
            while (running == true) {
                this_thread::sleep_for(interval);
                timeout();
            }
        });

        th.join();
    }

    void stop()
    {
        running = false;
    }
};

int main(void)
{
    Timer tHello, t2;
    tHello.start(chrono::microseconds(100000), []{
        cout << "Hello!" << endl;
    });

    t2.start(chrono::microseconds(100000), [] {
      cout << "aaa" << endl;
    });

    //this_thread::sleep_for(chrono::seconds(1));
    printf("awdwa");
    tHello.stop();
    return 0;
}
