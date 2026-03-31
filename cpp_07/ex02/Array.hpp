#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;
    public :
        Array();
        Array(unsigned int size);
        Array(const Array & other);
        ~Array();
        Array& operator=(const Array &other);
        unsigned int size() const;
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif