#include "PhoneBook.hpp"

Phonebook::Phonebook() : size(0) {}

Phonebook::~Phonebook()
{
}

bool isPrintableString(const std::string &s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isprint(s[i]))
            return false;
    }
    return true;
}

void Phonebook::addContact()
{
    static int count = 0;
    int index = count%8;
    std::string info;

    std::cout << "Enter the firstname:" << std::endl;
    std::getline(std::cin, info);
    if (isPrintableString(info) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    contacts[index].setFirstName(info);
    std::cout << "Enter the lastname:" << std::endl;
    std::getline(std::cin, info);
    if (isPrintableString(info) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    contacts[index].setLastName(info);
    std::cout << "Enter the nickname:"<< std::endl ;
    std::getline(std::cin, info);
    if (isPrintableString(info) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    contacts[index].setNickName(info);
    std::cout << "Enter the phone number:" << std::endl;
    std::getline(std::cin, info);
    if (isPrintableString(info) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    contacts[index].setPhoneNumber(info);
    std::cout << "Enter the darkest secret:" << std::endl;
    std::getline(std::cin, info);
    if (isPrintableString(info) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    contacts[index].setDarkestSecret(info);
    count++;
    if (count <= 8)
        size = count;
}


std::string form_field(std::string str)
{
    if(str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void displayContactRow(int index, const Contact &c) {
    std::cout << std::setw(10) << std::right << index << "|";
    std::cout << std::setw(10) << std::right << form_field(c.getFirstName()) << "|";
    std::cout << std::setw(10) << std::right << form_field(c.getLastName()) << "|";
    std::cout << std::setw(10) << std::right << form_field(c.getNickName()) << std::endl;
}

void Phonebook::displayInfos(int index)
{
    std::cout << "Fistname:       " << contacts[index].getFirstName() << std::endl;
    std::cout << "Lastname:       " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname:       " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone number:   " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void Phonebook::searchContact()
{
    std::string str;
    if(size == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        displayContactRow(i, contacts[i]);
    }
    std::cout << "enter the index of the contact to display infos (0~" << size - 1 << ")" <<std::endl;
    std::getline(std::cin, str);
    if (isPrintableString(str) == false) {
        std::cout << "Invalid input. Non-printable characters detected." << std::endl;
        return;
    }
    std::stringstream ss(str);
    int index;
    if (!(ss >> index)) {
        std::cout << "Invalid number!" << std::endl;
        return;
    }
    if (index >= 0 and index < size)
        displayInfos(index);
    else
        std::cout << "Invalid range!" << std::endl;
}

int main()
{
    Phonebook phonebook;
    std::string command;
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\n'CTRL+D' Exiting program..." << std::endl;
            break;
        }

        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
}
