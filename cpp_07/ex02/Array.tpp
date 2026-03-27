#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>
#include <new>


template<class T>
Array<T>::Array() : _elements(NULL), _size(0) {}


template<class T>
Array<T>::Array(unsigned int size): _size(size)
{
    if (size >  0)
        _elements = new T[size]();
    else
        _elements = 0;
}

template<class T>
Array<T>::Array(const Array & other): _elements(0), _size(0)
{
    *this = other;
}

template<class T>
Array<T> &Array<T>::operator=(const Array & other)
{
    if(this != &other)
    {
        delete[] _elements;
        _elements = 0;
        _size = other._size;
        if (_size > 0)
        {
            _elements = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i]; 
        }
    }
    return *this;
}

template<class T>
Array<T>::~Array()
{
    delete[] _elements;
}

template<class T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<class T>
T & Array<T>::operator[](unsigned int index)
{
    if(index >= _size)
        throw std::exception();
    return _elements[index];
}

template<class T>
const T & Array<T>::operator[](unsigned int index) const
{
    if(index >= _size)
        throw std::exception();
    return _elements[index];
}

#endif