#include <string>
#include <iostream>
#include <bits/stdc++.h>
class Base
{
    public:
        Base();
        Base(const Base& other);
        Base(const std::string& somthing, int x, int y);
        ~Base();
        Base& operator=(const Base& other);
        virtual void func(){std::cout<<"hello from base"<<std::endl;}
    protected:
        std::string somthing;
        int x;
        int y;
};

class Derived : public Base
{
    public:
        int d;
        ~Derived();
        Derived();
        Derived(const Derived& other);
        Derived(int d, const std::string& s, int x, int y);
        Derived& operator=(const Derived& other);
        void func(){std::cout << "hello from derived"<< std::endl;}
};

Base::Base():x(0),y(0),somthing("default")
{}

Base::Base(const Base& other):x(other.x),y(other.y),somthing(other.somthing)
{
}

Base::Base(const std::string& somthing, int x, int y):
somthing(somthing),x(x),y(y)
{
}

Base::~Base()
{
    std::cout<< "Base Destructor called"<< std::endl;
}
Base& Base::operator=(const Base& other)
{
    if (this != &other)
    {
        this->somthing = other.somthing;
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Derived::Derived(): Base() ,d(0)
{
}

Derived::~Derived()
{
    std::cout<< "Derived Destructor called"<< std::endl;
}

Derived::Derived(int d,const std::string& s, int x, int y):d(d),Base(s, x, y)
{
}

Derived& Derived::operator=(const Derived& other)
{
    if(this != &other)
    {
        Base::operator=(other);
        this->d = other.d;
    }
    return *this;
}


int main() {
    
    // Creating a pointer of type Base
    Base* basePtr;
    
    // Creating an object of Derived class
    Derived derivedObj;

    // Pointing base class pointer to 
    // derived class object
    basePtr = &derivedObj;
    
    // Calling the display function 
    // using base class pointer
    basePtr->func();
    return 0;
}