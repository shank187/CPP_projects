#ifndef SPAN_HPP
#define SPAN_HPP

class Span{
    private:
        unsigned int N;
        // to fill
    public:
        Span();
        Span(int n);
        Span(const Span & other);
        ~Span();
        Span& operator=(const Span & other);
        void addNumber(int n);
};

#endif