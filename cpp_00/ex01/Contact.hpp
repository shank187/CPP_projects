#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    std::string phoneNumber;

public:
    void setFirstName(std::string value) { firstName = value; }
    void setLastName(std::string value) { lastName = value; }
    void setNickName(std::string value) { nickname = value; }
    void setPhoneNumber(std::string value) { phoneNumber = value; }
    void setDarkestSecret(std::string value) { darkestSecret = value; }

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickName() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }

    Contact();
    ~Contact();
};

#endif
