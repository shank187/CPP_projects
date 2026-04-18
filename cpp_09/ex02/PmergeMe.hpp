#ifndef PMERGEME_hpp
#define PMERGEME_hpp


#include <deque>
#include <vector>
#include <string>

class PmergeMe{
    private:
        std::vector<std::vector<unsigned int>> vec;
        std::deque<std::deque<unsigned int>> deq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe & other);
        PmergeMe & operator+(const PmergeMe & other);
        PmergeMe(const std::string & arg);
        ~PmergeMe();

        void loadAndParse(const std::string & arg);
        void sortVecSequence();
        void sortDeqSequence();

        static bool is_in(char c, const std::string & s);
};


#endif