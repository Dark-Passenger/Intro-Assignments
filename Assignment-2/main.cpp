#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex locker;
bool isEvenPrinted = true;

void Print_Odd(int id, int end)
{
    int x = 1;
    while (x < end)
        {
            if (isEvenPrinted == true)
            {
                locker.lock();
                cout << "Thread ID : " << id << " : " << x << "\n";
                x += 2;
                locker.unlock();
                this_thread::yield();
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
            if (isEvenPrinted == false)
            {
                locker.lock();
                cout << "Thread ID : " << id << " : " << x << "\n";
                x += 2;
                locker.unlock();
                this_thread::yield();
                isEvenPrinted = true;
            }
            else
            {
                continue;
            }
        }
}

int main()
{
    int limit = 0;
    cout << "Enter limit : ";
    cin >> limit;

    thread Odd(Print_Odd, 1, limit);
    thread Even(Print_Even, 2, limit);

    Odd.join();
    Even.join();

    return 0;
}
