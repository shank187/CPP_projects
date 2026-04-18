#include "PmergeMe.hpp"
#include <sstream>
#include <climits>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe & other):vec(other.vec), deq(other.deq){}

PmergeMe::PmergeMe(const std::string & arg)
{
    this->loadAndParse(arg);
}

PmergeMe::~PmergeMe(){}

PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
    if(this != &other)
    {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

void PmergeMe::loadAndParse(const std::string & arg)
{
    std::stringstream ss(arg);
    std::string token;

    while (ss >> token)
    {
        for(int i = 0; i < token.length(); ++i)
            if(std::isdigit(token[i]))
                throw std::runtime_error("Error: Invalid character.");

        char *endptr;
        long val = std::strtol(token.c_str(), &endptr, 10);

        if(val > UINT_MAX || errno == ERANGE)
            throw std::runtime_error("Error: overflow|underflow.");

        unsigned int i = static_cast<unsigned int>(val);
        std::vector<unsigned int> innerVec;
        std::deque<unsigned int> innerDeq;
        
        innerVec.push_back(i);
        innerDeq.push_back(i);
        vec.push_back(innerVec);     
        deq.push_back(innerDeq);

    }
}