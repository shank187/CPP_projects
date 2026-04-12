#include "Span.hpp"
#include <algorithm>
#include <climits>

const char * Span::SpanFullException::what() const throw()
{
    return "Span is full, you cant add more numbers!";
}

const char * Span::TooFewEelementsException::what() const throw()
{
    return "No enough numbers to Calculate Span!";
}
Span::Span():N(0){}

Span::~Span(){}

Span::Span(int n):N(n){
    v.reserve(N);
}

Span::Span(const Span & other)
{
    this->N = other.N;
    this->v = other.v;
}

Span & Span::operator=(const Span & other)
{
    if(this != &other)
    {
        this->N = other.N;
        this->v = other.v;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if(v.size() >= N)
        throw SpanFullException();
    v.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if(v.size() < 2)
        throw TooFewEelementsException();
    std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());
    unsigned int min_span = static_cast<unsigned int>(tmp[1]) - tmp[0];

    for (std::size_t i = 2; i < tmp.size(); ++i)
    {
        unsigned int current_span = static_cast<unsigned int>(tmp[i]) - tmp[i - 1];
        if(current_span < min_span)
            min_span = current_span;
        if(min_span == 0)
            return 0;
    }
    return (min_span);
}

unsigned int Span::longestSpan()
{
    if(v.size() < 2)
        throw TooFewEelementsException();

    int min = *std::min_element(v.begin(), v.end());
    int max = *std::max_element(v.begin(), v.end());
    return(static_cast<unsigned int>(max) - min);
}


