#ifndef VAL_INC_HPP
#define VAL_INC_HPP

#include "Instructions.hpp"

class val_inc : public Instructions
{
    private:
    char _type;
    public:
        val_inc(){
            _type = '+';
        }
        char    *_ptr;
        val_inc(char *ptr) {
            _ptr = ptr;
        }
        ~val_inc(){}
        val_inc(const val_inc &a): _type(a._type) {}
        val_inc &operator=(const val_inc &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr){
            (*ptr)++;
            return  ptr;
        }
        virtual    char   getName()
        {
            return _type;
        }
};

#endif