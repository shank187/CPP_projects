#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(0));
    
    Base *ptr = generate();
    identify(*ptr);
    identify(ptr);
    delete ptr;
    
    ptr = generate();
    identify(*ptr);
    identify(ptr);
    delete ptr;

    ptr = generate();
    identify(*ptr);
    identify(ptr);
    delete ptr;

    D* d = new D();
    identify(*d);
    identify(d);
    delete d;

    return 0;
}