#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try {
        Span b(1);
        b.addNumber(3);
        b.addNumber(10);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        Span c(1);
        c.addNumber(3);
        std::cout << c.shortestSpan() << std::endl;
        std::cout << c.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        Span c(10);
        int x = 0;
        for(int i = 0; i < c.getsize(); i++)
        {
            x = x + 2;
            c.addNumber(x);
        }
        std::cout << c.shortestSpan() << std::endl;
        std::cout << c.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
    Span sp = Span(10);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(5);
    sp.addNumber(18);
    sp.addNumber(24);
    sp.addNumber(26);
    sp.addNumber(25);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}