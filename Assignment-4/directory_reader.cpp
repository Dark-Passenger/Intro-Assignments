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

void ReadDirectory(string directory)
{
  DIR *directorypointer;
  struct dirent *file;

  if((directorypointer = opendir(directory.c_str())) == NULL)
  {
    cout << "Error opening " << directory << "\n";
  }

  while (((file = readdir(directorypointer)) != NULL)&&(caughtSIGINT == false))
  {
    cout <<file->d_name<<"\n";
  }

  closedir(directorypointer);
}

int main()
{
  signal(SIGINT, signal_handler);
  string choice;
  string goagain;
  string directory;

  while(true) //infinite loop
  {

    cout << "Enter directory name : ";
    cin >> directory;
    ReadDirectory(directory);
    cout << "\n go again ? : (y/n)";
    cin >> goagain;

    if((caughtSIGINT == true)||(goagain == "n"))
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
    else
      cout << "Here we go again\n";
  }

  return 0;
}
