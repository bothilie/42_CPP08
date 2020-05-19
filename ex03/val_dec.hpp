#ifndef VAL_DEC_HPP
#define VAL_DEC_HPP

#include "Instructions.hpp"

class val_dec : public Instructions
{
    private:
    char _type;
    public:
        val_dec(){
            _type = '-';
        }
        char    *_ptr;
        val_dec(char *ptr) {
            _ptr = ptr;
        }
        ~val_dec(){}
        val_dec(const val_dec &a): _type(a._type) {}
        val_dec &operator=(const val_dec &a)
        {
            this->_type = a._type;
            return *this;
        }
       virtual char *execute(char *ptr){
            (*ptr)--;
            return ptr;
        }
        virtual char   getName()
        {
            return _type;
        }
};

#endif