#include "Span.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>

//constructors and destructors
Span::Span() : capacity(0), currentSize(0) {}
Span::Span(unsigned int N) : capacity(N) , currentSize(0) {}
Span::Span(const Span& other) : capacity(0), currentSize(0)
{
    *this = other;
}
Span::~Span() {}
//overloads
Span& Span::operator=(const Span& rhs)
{
    capacity = rhs.capacity;
    currentSize = rhs.currentSize;
    static_cast<std::vector<int>&>(*this) = rhs;
    return *this;
}
//methods
long Span::longestSpan()
{
    if (capacity < 2)
        throw Span::CantMeasureException();
    std::vector<int>::iterator start = begin();
    std::vector<int>::iterator last = end();
    long min = (long)*std::min_element(start, last);
    long max = (long)*std::max_element(start, last);
    return max - min;
}

//use longs to prevent overflow     
long safeDiff(int a, int b)
{
    return std::abs((long)b - (long)a);
}
long Span::shortestSpan()
{
    if (capacity < 2)
        throw Span::CantMeasureException();
    long     shortestSpan = INT_MAX;
    std::vector<int> copiedVector(static_cast<std::vector<int>&>(*this));
    std::sort(copiedVector.begin(), copiedVector.end());
    for (unsigned long i = 0; i < size() - 1; i++)
    {
        int a = copiedVector[i];
        int b = copiedVector[i + 1];
        long diff = safeDiff(a, b);
        if (shortestSpan > diff)
            shortestSpan = diff;
    }
    return shortestSpan;
}
void Span::addNumber(int nb)
{
    if (currentSize >= capacity)
        throw Span::SpanOutOfSpace();
    currentSize++;
    insert(begin(), nb);
}
void Span::addRange(int a, int z)
{
	if (size() + z - a >= capacity)
		throw Span::SpanOutOfSpace();
	for (int i = a; i <= z; i++)
		push_back(i);
}


const char* Span::CantMeasureException::what() const throw()
{
    return "Cant measure span!";
}
const char* Span::SpanOutOfSpace::what() const throw()
{
    return "span out of space!";
}