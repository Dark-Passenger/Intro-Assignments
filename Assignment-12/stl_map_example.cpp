#include <iostream>
#include <string>
#include <map>

class Contact
{
    private:
        std::map <std::string,unsigned long int> contacts;

    public:
        void search_by_name()
        {
            std::string name;
            std::cout << "Enter name : ";
            std::cin >> name;
            if(name.empty() == false)
            {
                std::cout <<"Number belonging to contact "<< name <<" is : " << contacts[name] << std::endl;
            }
            else
                std::cout <<"Name does not exist" << std::endl;
        }

        void search_by_number()
        {
            unsigned long int number = 0;
            std::cout << "Enter the number : ";
            std::cin >> number;

            for(auto& contact : contacts)
            {
                if (contact.second == number)
                {
                    std::cout << number <<" belongs to contact " << contact.first << std::endl;
                    break;
                }
            }
        }

        void list()
        {
            std::cout <<"Name\tNumber" << std::endl;
            for (auto& contact : contacts)
            {
                std::cout << contact.first << "\t" << contact.second << std::endl;
            }
        }

        void add()
        {
            std::string name;
            unsigned long int number;
            std::cout <<"Name : ";
            std::cin >>name;
            std::cout <<"number : ";
            std::cin >>number;
            contacts[name] = number;
            std::cout << "Contact created successfully" << std::endl;
        }

        void remove()
        {
            std::string name;
            std::cout <<"Name : ";
            std::cin >>name;
            contacts.erase(name);
            std::cout << "Contact removed successfully" << std::endl;
        }
};

int main()
{
    Contact con;
    int choice = 0;

    do
    {
        std::cout <<"1. search for name" << std::endl;
        std::cout <<"2. search by number" << std::endl;
        std::cout <<"3. list all contacts" << std::endl;
        std::cout <<"4. add contact" << std::endl;
        std::cout <<"5. remove contact" << std::endl;
        std::cout <<"6. Exit" << std::endl;
        std::cout <<"Enter your choice : ";
        std::cin >> choice;

        switch(choice)
        {
            case 1 :
                con.search_by_name();
                break;

            case 2 :
                con.search_by_number();
                break;

            case 3 :
                con.list();
                break;

            case 4 :
                con.add();
                break;

            case 5 :
                con.remove();
                break;

            case 6 :
                break;

            default :
                std::cout <<"wrong choice try again" << std::endl;
        }

    } while (choice != 6);

    return 0;
}
