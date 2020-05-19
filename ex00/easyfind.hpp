#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class NotFoundException: public std::exception
{
    public:
        virtual const char* what() const throw();
};

template <typename T>
int &easyfind(T &a, int n)
{
    typename T::iterator it = find(a.begin(), a.end(), n);

    if (it == a.end())
        throw NotFoundException();
    return *it;
}

#endif