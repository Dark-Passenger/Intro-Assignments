#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
    ofstream file;
    string file_name = "/var/log/time.log";
    int sleep_time = 300;

    daemon(1,1);    //make a daemon

    while(true)
    {
        time_t end_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        file.open(file_name, ofstream::app);
        file << ctime(&end_time);
        file.close();
        sleep(sleep_time);
    }

    return 0;
}