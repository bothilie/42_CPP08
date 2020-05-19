#ifndef PTR_INC_HPP
#define PTR_INC_HPP

#include "Instructions.hpp"

class Ptr_inc : public Instructions
{
    private:
    char _type;
    public:
        Ptr_inc(){ _type = '>';}
        char    *_ptr;
        Ptr_inc(char *ptr);
        ~Ptr_inc(){}
        Ptr_inc(const Ptr_inc &a): _type(a._type) {}
        Ptr_inc &operator=(const Ptr_inc &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr)
        {
            return ++ptr;
        }
        virtual    char   getName()
        {
            return _type;
        }
};

#endif