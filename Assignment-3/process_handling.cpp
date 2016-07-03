#include <iostream>
#include <vector>
#include <unistd.h>

using namespace  std;

vector<pid_t> children;
vector<pid_t>::iterator child;

void KillAllChildren()
{
	child = children.begin();
	
	while( child != children.end())
	{
   		kill(*child, SIGTERM);
   		child++;
   	}
}

void KillLastChild()
{
	child = children.begin();

	if (children.empty() == false)
	{
		kill(children.back(), SIGTERM);	// also try *children.back()
		children.pop_back();		// remove the dead child from the list of children
	}
}

void ListAllChildren()
{
	child = children.begin();
	cout << "Current Child Processes are : \n";
	while( child != children.end())
	{
   		cout << *child << "\n";
   		child++;
   	}
}

void CreateChild()
{
	pid_t pid;

	if((pid = fork()) == 0)
	{
     //child process will now sleep for 2 hrs.
		cout << "Child process with process id : " << pid << "Created.\n";
		cout << "Putting child to sleep...";
		sleep(3600);
	}
	else
	{
	//add child process pid into children vector.
		children.push_back(pid);
	}
}

int main ()
{
	int choice;

	while (true)
	{
		cout <<"1. Create\n"; 
		cout <<"2. Terminate\n";		//Assumed to terminate the last created process.
		cout <<"3. List\n";
		cout <<"4. Exit\n";
		cout <<"Enter choice : ";
		cin >>choice;

		switch(choice)
		{
			case 1 :
				CreateChild();
				break;
			case 2 :
				KillLastChild();
				break;
			case 3 :
				ListAllChildren();
				break;
			case 4 :
				KillAllChildren();
				return 0;			//exits aftering killing all the child processes.
			default :
				cout << "Wrong option try again";
				break;	
		}
	}
	
	return 0;
}
