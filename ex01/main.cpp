#include <cstddef>
#include <iostream>
#include <span>
#include <vector>
#include "Span.hpp"
#include <stack>
#include <bits/stdc++.h>

void ft_print(std::string str)
{
    std::cout << str << std::endl;
}

void MeasureSpans(Span& sp)
{
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void invalidSizeTest()
{
    Span sp = Span(10000);
    std::cout << "adding 10000 numbers to span with add number" << std::endl;
    for (size_t i = 0; i < 10000; i++)
        sp.addNumber(3);
    try
    {
        std::cout << "adding one extra number" << std::endl;
        sp.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught an error as expected: \"" << e.what() << "\"\n";
    }
}

void validSpanMeasurmentTests()
{
    Span sp = Span(10000);
    std::cout << "adding INT_MIN" << std::endl;
    sp.addNumber(INT_MIN);
    std::cout << "adding 5000 numbers to span with add number" << std::endl;
    for (size_t i = 0; i < 5000; i++)
        sp.addNumber(3);
    std::cout << "adding INT_MAX" << std::endl;
    sp.addNumber(INT_MAX);
    MeasureSpans(sp);
}

void invalidSpanMeasurmentTests()
{
    Span sp = Span(10000);
    std::cout << "adding INT_MAX" << std::endl;
    sp.addNumber(INT_MAX);
    try
    {
        MeasureSpans(sp);
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught an error as expected: \"" << e.what() << "\"\n";
    }
}

void addRangeTest()
{
    Span sp(20);
    ft_print("adding 10 numbers:");
    for (int i = 0; i < 10; i++)
        sp.addNumber(i);
    for (int i = 0; i < 10; i++)
        std::cout << "sp[" << i << "]= " << sp[i] << std::endl;
    ft_print("Adding 10 other numbers with addRange:");
    Span cpy(sp);
    sp.addRange(cpy.begin(), cpy.end());
    for (int i = 0; i < 20; i++)
        std::cout << "sp[" << i << "]= " << sp[i] << std::endl;
}

int main()
{
    std::cout << "INT_MAX - INT_MIN = " << ((long)INT_MAX - (long)INT_MIN) << std::endl;
    ft_print("--------------invalidSizeTest--------------");
    invalidSizeTest();
    ft_print("--------------validSpanMeasurmentTests--------------");
    validSpanMeasurmentTests();
    ft_print("--------------invalidSpanMeasurmentTests--------------");
    invalidSpanMeasurmentTests();
    ft_print("--------------addRangeTest--------------");
    addRangeTest();
}