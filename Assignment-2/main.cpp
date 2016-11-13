#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>


std::mutex locker;
std::atomic<bool> isEvenPrinted(true);

void Print_Odd(int id, int end)
{
    int x = 1;
    while (x < end)
        {
            if (isEvenPrinted.load() == true)
            {
                locker.lock();
                std::cout << "Thread ID : " << id << " : " << x << "\n";
                x += 2;
                locker.unlock();
                std::this_thread::yield();
                isEvenPrinted = false;
            }
            else
            {
                continue;
            }
        }
}

void Print_Even(int id, int end)
{
    int x = 2;
    while (x < end)
        {
            if (isEvenPrinted.load() == false)
            {
                locker.lock();
                std::cout << "Thread ID : " << id << " : " << x << "\n";
                x += 2;
                locker.unlock();
                std::this_thread::yield();
                isEvenPrinted = true;
            }
        }
}

int main()
{
    int limit = 0;
    std::cout << "Enter limit : ";
    std::cin >> limit;

    std::thread Odd(Print_Odd, 1, limit);
    std::thread Even(Print_Even, 2, limit);

    Odd.join();
    Even.join();

    return 0;
}
