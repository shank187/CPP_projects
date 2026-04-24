#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <ctime>

class PmergeMe {
private:
    std::vector<std::vector<unsigned int> > vec;
    std::deque<std::deque<unsigned int> > deq;
    std::size_t _originalSize;

    template <typename Container>
    struct CompareFront {
        bool operator()(const Container& a, const Container& b) const {
            return a[0] < b[0];
        }
    };

    template <typename T>
    void recursiveSort(T & matrix) {
        if (matrix.size() < 2) return;

        typename T::value_type levelStraggler;
        bool hasLevelStraggler = false;
        if (matrix.size() % 2 != 0) {
            levelStraggler = matrix.back();
            matrix.pop_back();
            hasLevelStraggler = true;
        }

        T nextLevel;
        for (size_t i = 0; i < matrix.size(); i += 2) {
            if (matrix[i][0] < matrix[i + 1][0])
                std::swap(matrix[i], matrix[i + 1]);
            matrix[i].insert(matrix[i].end(), matrix[i + 1].begin(), matrix[i + 1].end());
            nextLevel.push_back(matrix[i]);
        }

        recursiveSort(nextLevel);

        size_t pair_size = nextLevel[0].size() / 2;
        T main_chain;
        T pend_chain;

        for (size_t i = 0; i < nextLevel.size(); ++i) {
            typename T::value_type winner_part(nextLevel[i].begin(), nextLevel[i].begin() + pair_size);
            typename T::value_type loser_part(nextLevel[i].begin() + pair_size, nextLevel[i].end());
            main_chain.push_back(winner_part);
            pend_chain.push_back(loser_part);
        }
        if (hasLevelStraggler) pend_chain.push_back(levelStraggler);

        main_chain.insert(main_chain.begin(), pend_chain[0]);
        
        std::vector<size_t> jacobs = generateJacobs(pend_chain.size());
        size_t last_jacob = 1;

        for (size_t j = 0; j < jacobs.size(); ++j) {
            size_t current_jacob = jacobs[j];
            for (size_t k = current_jacob; k > last_jacob; --k) {
                if (k > pend_chain.size()) continue;

                bool isStraggler = hasLevelStraggler && (k - 1 == pend_chain.size() - 1);

                typename T::iterator search_end = main_chain.end();
                if(!isStraggler)
                {
                    search_end = main_chain.begin();
                    unsigned int target_boss = nextLevel[k-1][0];
                    while (search_end != main_chain.end()) {
                        if ((*search_end)[0] == target_boss) {
                            break;
                        }
                        ++search_end;
                    }
                }
                typename T::iterator bound = std::lower_bound(main_chain.begin(), search_end, 
                                                            pend_chain[k-1], CompareFront<typename T::value_type>());
                main_chain.insert(bound, pend_chain[k-1]);
            }
            last_jacob = current_jacob;
        }
        matrix = main_chain;
    }

    std::vector<size_t> generateJacobs(size_t n);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe & other);
    PmergeMe(const PmergeMe & other);
    void loadAndParse(int ac, char **av);
    void solve();
};

#endif