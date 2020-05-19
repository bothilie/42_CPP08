#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        typedef typename std::deque<T>::iterator iterator;
        MutantStack(): std::stack<T>() {};
        virtual ~MutantStack(){}
        MutantStack(const MutantStack &a) : std::stack<T>(a) {}
        MutantStack &operator=(const MutantStack &a);
        iterator begin(){return this->c.begin();}
        iterator end() {return this->c.end();}
};

#endif