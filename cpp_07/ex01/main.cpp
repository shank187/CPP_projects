#include "iter.hpp"
#include <iostream>

int main() {
    int arr[] = {1, 2, 3};
    const int c_arr[] = {10, 20, 30};
    std::cout << "normal arr test:" << std::endl;
    iter(arr, 3, print<int>);
    
    iter(arr, 3, increment<int>);
    
    std::cout << "\nincremented normal arr:" << std::endl;
    iter(arr, 3, print<int>);
    
    std::cout << "\nconst arr test:" << std::endl;
    iter(c_arr, 3, print<int>);

    return 0;
}