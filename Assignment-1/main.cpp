#include <iostream>
#include "shared.h"		//we include the class that is compiled into the shared library.

using namespace std;

int main(int argc, char *argv[])
{
  sharedclass libshare;		//object of the shared library class.
  int a = 0;
  int b = 0;
  int choice;
  int result;
  bool flag = false;

  cout<<"Enter first number : ";
  cin>>a;
  cout<<"Enter second number : ";
  cin>>b;

  do
  {
  
    cout<<"1. Addition\n";
    cout<<"2. Subtraction\n";
    cout<<"3. Multiplication\n";
    cout<<"4. Division\n";
    cout<<"5. Exit\n";
    cout<<"Enter selection : ";
    cin>>choice;

    switch(choice)
        {
          case 1 :
                result = libshare.add(a,b);
                break; 
          case 2 :
                result = libshare.subtract(a,b);
                break;
          case 3 :
                result = libshare.multiply(a,b);
                break;
          case 4 :
                result = libshare.divide(a,b);
                break;
          case 5 :
          	flag = true;
          	break;

          default :
                cout<<"Wrong choice try again";
    	          result = 0;
	     }

	if(flag==false)	//this is so that when user exits the result of any previous operations is not shown.
		{
			cout<<"Result is : "<<result"\n";
		}

    }while((flag == false) && (choice < 5));	//we check for the exit flag and also if the user has chosen to exit.

}
