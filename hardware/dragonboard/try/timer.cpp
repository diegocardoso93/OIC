#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Timer
{
    thread th;
    bool running = false;

public:
    typedef chrono::microseconds Interval;
    typedef function<void(void)> Timeout;

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
    Timer tHello;
    tHello.start(chrono::microseconds(1000), []{
        cout << "Hello!" << endl;
    });

    this_thread::sleep_for(chrono::seconds(1));
    tHello.stop();
    return 0;
}