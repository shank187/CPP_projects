#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{

    public:
        typedef typename  std::stack<T>::container_type::iterator iterator;
        typedef typename  std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename  std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename  std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack & other);
        MutantStack & operator=(const MutantStack & other);

        iterator begin();
        iterator end();

};



#include "MutantStack.tpp"

#endif