#include "span.hpp"
#include <iostream>

Span::Span(unsigned int n): _size(n)
{
}

void Span::addNumber(int i)
{
    if (tab.size() == _size)
        throw Span::FullArrayException();
    tab.push_back(i);
}

int Span::shortestSpan(){
    if (tab.size() <= 1)
       throw Span::OneElemException();
    std::sort(tab.begin(), tab.begin() + _size - 1);
    std::vector<int>::iterator it;
    int min = abs(*tab.begin() - tab[1]);
    int tmp = *it;
    for (it = tab.begin() + 1; it != tab.end(); it++)
    {
        if (abs(*it - tmp) < min)
            min = abs(*it - tmp);
        tmp = *it;
    }
    return min;
}

int Span::longestSpan(){
    std::vector<int>::iterator max = max_element(tab.begin(), tab.end());
    std::vector<int>::iterator min = min_element(tab.begin(), tab.end());
    return *max - *min;
}

const char *Span::FullArrayException::what() const throw()
{
    return "Full Array Exception";
}

const char *Span::OneElemException::what() const throw()
{
    return "There is only one element in the array";
}

int Span::getsize() const
{
    return _size;
}

Span::Span(const Span &a): tab(a.tab), _size(a._size)
{}

Span &Span::operator=(Span const &a)
{
    _size = a._size;
    tab = a.tab;
    return *this;
}

Span::~Span() {}

