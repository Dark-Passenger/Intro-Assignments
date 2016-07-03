#include <iostream>
#include <cstring>
#include <signal.h> 
#include <dirent.h>

using namespace std;

bool caughtSIGINT = false;

void signal_handler(int sig)
{
  caughtSIGINT = true;
}

bool ReadDirectory(string directory)
{
  DIR *directorypointer;
  struct dirent *file;

  if((directorypointer = opendir(directory.c_str())) == NULL)
  {
    return false;
  }

  while (((file = readdir(directorypointer)) != NULL)&&(caughtSIGINT == false))
  {
    cout <<file->d_name<<"\n";
  }

  closedir(directorypointer);
  return true;
}

int main()
{
  signal(SIGINT, signal_handler);
  string choice;
  string goagain;
  string directory;
  bool readSuccessful;

  while(true) //infinite loop
  {

    cout << "Enter directory name : ";
    cin >> directory;
    readSuccessful = ReadDirectory(directory);
    if (readSuccessful == false)
      cout << "oops error opening directory \n"
    
    cout << "go again ? (y/n) : ";
    cin >> goagain;

    if(caughtSIGINT == true)
    {
      cout << "\nDo you want to quit ? (y/n) : ";
      cin >> choice;
      if (choice == "y")
      {
        break;
      }
      else
      {
        caughtSIGINT = false;
      }
    }
  }

  return 0;
}
