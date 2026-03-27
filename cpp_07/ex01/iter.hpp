#ifndef ITER_HPP
#define ITER_HPP



#include <cstddef>

template <typename T, typename F>
void iter(T *arr, const size_t length, F func)
{
    for (size_t i = 0; i < length; i++) {
        func(arr[i]);
    }
}


#endif // ITER_HPP