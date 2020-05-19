#include "easyfind.hpp"
#include <vector>
#include <iterator>
#include <iostream>

const char* NotFoundException::what() const throw()
    {
        return "Element not found";
    }

int main()
{
    std::vector<int> tab(1,1);
    tab.push_back(2);
    tab.push_back(3);
    int c;
    try {
    c = easyfind(tab, 1);
    std::cout << "Element find " << c << std::endl; 
    c = easyfind(tab, 3);
    std::cout << "Element find " << c << std::endl; 
    c = easyfind(tab, 13);
    std::cout << "Element find " << c << std::endl; 
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}