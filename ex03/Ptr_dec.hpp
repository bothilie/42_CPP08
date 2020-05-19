#ifndef PTR_DEC_HPP
#define PTR_DEC_HPP

#include "Instructions.hpp"

class Ptr_dec : public Instructions
{
    private:
    char    _type;
    public:
        Ptr_dec(){ _type = '<';}
        char    *_ptr;
        Ptr_dec(char *ptr) {
            _ptr = ptr;
        }
        ~Ptr_dec(){}
        Ptr_dec(const Ptr_dec &a): _type(a._type) {}
        Ptr_dec &operator=(const Ptr_dec &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr) {
            return --ptr;
        }
        virtual        char   getName()
        {
            return _type;
        }
};

#endif