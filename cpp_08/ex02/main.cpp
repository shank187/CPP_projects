#include "MutantStack.hpp"
#include <iostream>


int main(void)
{
    int values[] = {3, 66, 1 , 8, 7, 86, 0, -1};

    MutantStack<int> ms;

    for(size_t i = 0; i < sizeof(values)/ sizeof(int); ++i)
        ms.push(values[i]);

    for(MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << "the top of mutant stack is :" << ms.top() << std::endl;
    ms.pop();
    std::cout << "the top after poping :" << ms.top() << std::endl;

}