#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

class Span : protected std::vector<int>
{
    private:
    unsigned int capacity;
    size_type currentSize;

    public:
    //constructors and destructors
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    //overloads
    Span& operator=(const Span& rhs);
    //methods
    long shortestSpan();
    long longestSpan();
    void addNumber(int nb);
    void addRange(int a, int z);
    //member classes
    class CantMeasureException : public std::exception
    {
        public :
        const char* what() const throw();
    };
    class SpanOutOfSpace : public std::exception
    {
        public :
        const char* what() const throw();
    };
};
#endif