#include <iostream>
#include <string>
#include <map>

using namespace std;

class Contact
{

private:
	map <string, int> contacts;

void searcher(string search_term)
{
	string search_term;
	cout <<"Enter search term : ";
	cin >> search_term;

   if(s.empty() || (isdigit(s[0])==false))
   	{
   		cout <<"Number belonging to contact "<< search_term <<" is : " << contacts.find(search_term)->second <<"\n";
   	}

   else	//this is a far more resource intensive process. TODO check if stoi iteratively is better than storing value in variable.
   {
		number = stoi(search_term);
		for (map<string, int>::iterator itr = contacts.begin(); itr != contacts.end(); ++itr)
		{
			if (itr->second == search_number)
			{
				cout <<search_term <<" belongs to contact " << itr->first <<"\n";
				break;
			}
		}
   }

}

void lister()
{
	cout <<"Name\tNumber\n";
	for (map<string, int>::iterator itr = contacts.begin(); itr != contacts.end(); ++itr)
		{
			cout << itr->first "\t" << itr->second "\n";
		}
}

void adder()
{
	string name;
	int number;
	cout <<"Name : ";
	cin >>name;
	cout <<"number : ";
	cin >>number;
	contacts[name] = number;
	cout << "Contact created successfully\n";
}

void remover()
{
	string name;
	cout <<"Name : ";
	cin >>name;
	contacts.erase(name); 
	cout << "Contact removed successfully\n";
}
};

int main()
{
	Contact con;

	while(true){

	cout <<"1. search for name\n";
	cout <<"2. search by number\n";
	cout <<"3. list all contacts\n";
	cout <<"4. add contact\n";
	cout <<"5. remove contact\n";
	cout <<"6. Exit\n";
	cout <<"Enter your choice : ";
	cin >> choice;
	
	switch(choice)
	{
	case 1 : con.searcher();
		break;

	case 2 : con.searcher();
		break;

	case 3 : con.lister();
		break;

	case 4 : con.adder();
		break;

	case 5 : con.remover();
		break;

	case 6 : return 0;

	default : cout <<"wrong choice try again\n";
		break;
	}
}
	return 0;
}
