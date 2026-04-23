#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include<list>

int main(void)
{
    int values[] = {3, 66, 1 , 8, 7, 86, 0, -1};
    std::vector<int> vec(values, values + sizeof(values)/ sizeof(int));
    std::list<int> lst(values, values + sizeof(values)/ sizeof(int));
    
    try
    {
        std::vector<int>::iterator it =  easyfind(vec, 1);
        std::cout << "the number " <<*it << " exist in the caontainer." << std::endl;
        std::vector<int>::iterator itr =  easyfind(vec, 42);
        std::cout << "the number " <<*itr << " exist in the caontainer." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::list<int>::iterator it =  easyfind(lst, 1);
        std::cout << "the number " <<*it << " exist in the caontainer." << std::endl;
        std::list<int>::iterator itr =  easyfind(lst, 42);
        std::cout << "the number " <<*itr << " exist in the caontainer." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}