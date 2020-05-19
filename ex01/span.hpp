#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iostream>

class Span
{
    private:
        std::vector<int> tab;
        unsigned int _size;
        Span(){}
    public:
        class FullArrayException: public std::exception 
        {
            virtual const char *what() const throw();
        };
        class OneElemException: public std::exception 
        {
            virtual const char *what() const throw();
        };
        Span(unsigned int n);
        Span(const Span &a);
        Span &operator=(Span const &a);
        ~Span();
        void addNumber(int i);
        int shortestSpan();
        int longestSpan();
        int getsize() const;
};

#endif