#include "mutantstack.hpp"
#include <iostream>
#include <stack>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "mstack" << std::endl;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
    ++it; }
    std::cout << mstack.empty() <<std::endl;
    MutantStack<int> other;
    other.push(19);
    other.swap(mstack);
    std::cout << "mstack" << std::endl;
    for (it = mstack.begin(); it != mstack.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "other" << std::endl;
    for (it = other.begin(); it != other.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "lala" << std::endl;
    MutantStack<int> lala(other);
    for (it = lala.begin(); it != lala.end(); it++)
    {
        std::cout << *it << std::endl;
    }
        std::cout << "lolo" << std::endl;
    MutantStack<int> lolo = lala;
    for (it = lolo.begin(); it != lolo.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}