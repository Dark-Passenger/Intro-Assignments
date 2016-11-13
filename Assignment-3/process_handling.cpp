#include <iostream>
#include <vector>
#include <unistd.h>
#include <signal.h>


std::vector<pid_t> children;

void KillAllChildren()
{

    for( auto child : children)
    {
        kill(child, SIGTERM);
    }

    std::cout << "All children killed." << std::endl;
}

void KillLastChild()
{

    if (children.empty())
    {
        std::cout << "No children present." << std::endl;
    }
    else
    {
        kill(children.back(), SIGTERM);
        std::cout << "Killed child " << children.back() << std::endl;
        children.pop_back();        // remove the dead child from the list of children
    }
}

void ListAllChildren()
{
    std::cout << "Current Child Processes are : " << std::endl;
    for( auto child : children)
    {
        std::cout << child << std::endl;
    }
}

void CreateChild()
{
    pid_t pid;

    if((pid = fork()) == 0)
    {
        //child process will now sleep for 2 hrs.
        sleep(3600);
    }
    else
    {
    //add child process pid into children vector.
        children.push_back(pid);
        std::cout << "Child process with process id : " << pid << "Created." << std::endl;
    }
}

int main()
{
    int choice;

    do
    {
        std::cout << "1. Create" << std::endl;
        std::cout << "2. Terminate" << std::endl;        //Assumed to terminate the last created process.
        std::cout << "3. List" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice : ";
        std::cin >> choice;

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
                std::cout << "Exiting" << std::endl;
                break;
            default :
                std::cout << "Wrong option try again" << std::endl;
                break;
        }

    } while(choice !=4);

    return 0;
}
