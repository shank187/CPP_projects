#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"
#include <set> 

int main()
{
    // Ready subj test
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout <<"shortest Span is: "<< sp.shortestSpan() << std::endl;
    std::cout <<"longest Span is: "<< sp.longestSpan() << std::endl;

    // my tests
    std::srand(time(NULL));
    unsigned int total = 10001;
    Span sn(total);
    std::set<int> uniuques;

    while(uniuques.size() < total)
        uniuques.insert(std::rand() % 10000000);
    try
    {
        sn.addNumber(uniuques.begin(), uniuques.end());
        std::cout <<"shortest Span is: "<< sn.shortestSpan() << std::endl;
        std::cout <<"longest Span is: "<< sn.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}