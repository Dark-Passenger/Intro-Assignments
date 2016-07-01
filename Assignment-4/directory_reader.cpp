#include <iostream>
#include <cstring>
#include <dirent.h>
#include <signal.h>

using namespace std;

class Directory_Raider
{
private:
    DIR *directory;
	struct dirent *result;
     
public:
   void DReader(string);
   bool signal_handler(sig_t);
};
 
void Directory_Raider::DReader(string name)
{
    
	if ((directory = opendir (name)) != NULL) 
	{
  	/* print all the results and directories within directory */
  		while ((file = readdir (directory)) != NULL)
  		{
    		cout<<file->d_name<<"\n";
  		}
  		closedir (directory);
	}
	else
	{
  		perror ("Could not open directory");
  		return EXIT_FAILURE;
	}
}

bool Directory_Raider::signal_handler(sig_t s)
{
  string choice;

  cout<<"Do you want to quit ? ";
  cin>>choice;
  if(((choice[0]=="n")||(choice[0]=="N"))&&(choice.length()==2))
  {
    return true;
  }
  else
  {
    return false;
    //exit(1);
  }
}
 
int main(int argc , char *argv[])
{
	Directory_Raider direct;
	string name;
  bool flag == true;

  while(flag==true)
  {
      cout<<"Enter directory to list : ";
      cin>>name;
      direct.DReader(name);
      flag = signal(SIGINT,direct.signal_handler);
  }

  return 0;
}
