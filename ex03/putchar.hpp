#ifndef PUTCHAR_HPP
#define PUTCHAR_HPP

#include "Instructions.hpp"
#include <iostream>

class put_char : public Instructions
{
    private:
    char _type;
    public:
        put_char(){
            _type = '.';
        }
        char    *_ptr;
        put_char(char *ptr);
        ~put_char(){}
        put_char(const put_char &a): _type(a._type) {}
        put_char &operator=(const put_char &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr)
        {
            std::cout << *ptr;
            return ptr;
        }
        virtual    char   getName()
        {
            return _type;
        }
};

#endif