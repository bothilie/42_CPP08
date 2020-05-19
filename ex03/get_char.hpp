#ifndef GET_CHAR_HPP
#define GET_CHAR_HPP

#include "Instructions.hpp"
#include <iostream>
#include <stdio.h>

class get_char : public Instructions
{
    private:
    char _type;
    public:
        get_char(){
            _type = ',';
        }
        char    *_ptr;
        get_char(char *ptr);
        ~get_char(){}
        get_char(const get_char &a): _type(a._type) {}
        get_char &operator=(const get_char &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr)
        {
            *ptr = getchar();
            return ptr;
        }
        virtual         char   getName()
        {
            return _type;
        }
};

#endif