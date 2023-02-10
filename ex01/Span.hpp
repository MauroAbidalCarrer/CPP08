#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

class Span : public std::vector<int>
{
    private:
    unsigned int capacity;

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
    void addRange(std::vector<int>::iterator start, std::vector<int>::iterator last);
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