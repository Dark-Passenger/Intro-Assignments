#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

bool isChildDone = false;
bool isSigCaught = false;

void parent_signal_handler(int sig)
{
	cout <<"Parent Signal recieved exiting\n";
	isChildDone = true;
}

void child_signal_handler(int sig)
{
	int status;
	int status_code = WEXITSTATUS(status);
	cout <<"Child exited with status code : " << status_code << "\n";
	Dead = true;
}

int Main()
{
	pid_t pid;

	if((pid = fork()) == 0)
	{
     	//child action
		signal(SIGUSR1, child_signal_handler);
		while(true)
		{
			cout <<"Child waiting\n";
			if(isSigCaught == true)
				return 0;
		}
	}
	else
	{
		//parent action
		signal(SIGCHLD, parent_signal_handler);
		sleep(5);
		kill(pid, SIGUSR1);
		while(true)
		{
			cout <<"Parent waiting\n";
			if(isChildDone == true)
				return 0;
		}
	}
}
