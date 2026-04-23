#include "Harl.hpp"
#include <iostream>
Harl::Harl() {}
Harl::~Harl() {}
void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"<< std::endl;
}
void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!\n"<< std::endl;
}
void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming here for years and there’s never enough bacon!\n"<< std::endl;
}
void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"<< std::endl;
}
// In Harl.cpp
void Harl::complain(std::string level) {
    void (Harl::*complainMethods[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            switch (i) {
                case 0:
                    (this->*complainMethods[0])();
                    // fall through
                case 1:
                    (this->*complainMethods[1])();
                    // fall through
                case 2:
                    (this->*complainMethods[2])();
                    // fall through
                case 3:
                    (this->*complainMethods[3])();
                    break;
            }
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}