#include <cstddef>
#include <iostream>
#include <span>
#include <vector>
#include "Span.hpp"
#include <stack>


int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addRange(9, 10000);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}