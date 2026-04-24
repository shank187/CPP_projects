#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <errno.h>
#include <cstdlib>
#include <cctype>

PmergeMe::PmergeMe() : _originalSize(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other):vec(other.vec), deq(other.deq), _originalSize(other._originalSize){}

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{
    if(this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
        this->_originalSize = other._originalSize;
    }
    return *this;
}

std::vector<size_t> PmergeMe::generateJacobs(size_t n) {
    std::vector<size_t> j;
    if (n <= 1) return j;
    j.push_back(3);
    j.push_back(5);
    while (j.back() < n)
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
    return j;
}

void PmergeMe::loadAndParse(int ac, char **av) {
    std::string fullInput = "";
    for (int i = 1; i < ac; ++i) {
        fullInput += av[i];
        fullInput += " ";
    }
    std::stringstream ss(fullInput);
    std::string token;
    while (ss >> token) {
        for (size_t i = 0; i < token.length(); ++i)
            if (!isdigit(token[i])) throw std::runtime_error("Error: Not a positive integer.");
        
        char *ptr;
        long val = strtol(token.c_str(), &ptr, 10);
        if (errno == ERANGE || val > UINT_MAX) throw std::runtime_error("Error: Overflow.");

        std::vector<unsigned int> v; v.push_back(static_cast<unsigned int>(val));
        std::deque<unsigned int> d; d.push_back(static_cast<unsigned int>(val));
        vec.push_back(v);
        deq.push_back(d);
    }
    _originalSize = vec.size();
}

void PmergeMe::solve() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i == 4 && vec.size() > 5) {
            std::cout << "[...] ";
            break;
        }
        std::cout << vec[i][0] << " ";
    }    std::cout << std::endl;

    clock_t startV = clock();
    recursiveSort(vec);
    clock_t endV = clock();

    clock_t startD = clock();
    recursiveSort(deq);
    clock_t endD = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i == 4 && vec.size() > 5) {
            std::cout << "[...] ";
            break;
        }
        std::cout << vec[i][0] << " ";
    }    std::cout << std::endl;

    double timeV = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1000000;
    double timeD = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _originalSize << " elements with std::vector : " << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _originalSize << " elements with std::deque  : " << timeD << " us" << std::endl;
}

