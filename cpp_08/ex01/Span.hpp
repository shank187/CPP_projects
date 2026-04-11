#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span{
    private:
        unsigned int N;
        std::vector <int> v;
    public:
        class SpanFullException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class TooFewEelementsException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        Span();
        Span(int n);
        Span(const Span & other);
        ~Span();
        Span& operator=(const Span & other);
        
        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif