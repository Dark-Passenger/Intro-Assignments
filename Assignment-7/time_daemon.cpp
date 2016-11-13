#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <unistd.h>

int main()
{
    std::ofstream file;
    std::string const file_name = "/var/log/time.log";
    int const sleep_time = 300;

    daemon(1,1);    //make a daemon

    while(true)
    {
        time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        file.open(file_name, std::ofstream::app);
        file << std::ctime(&end_time);
        file.close();
        sleep(sleep_time);
    }

}
