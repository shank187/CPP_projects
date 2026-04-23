#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Phonebook
{
private:
    Contact contacts[8];
    int size;
public:
    void addContact();
    void searchContact();
    void displayInfos(int index);
    Phonebook();
    ~Phonebook();
};

bool isPrintableString(const std::string &s);

#endif
