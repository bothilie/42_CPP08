#ifndef END_PTR_HPP
#define END_PTR_HPP

#include "Instructions.hpp"

class end_ptr : public Instructions
{
    private:
    char        _type;
    public:
        end_ptr(){  _type = ']';}
        char    *_ptr;
        end_ptr(char *ptr) {
            _ptr = ptr;
        }
        ~end_ptr(){}
        end_ptr(const end_ptr &a): _type(a._type) {}
        end_ptr &operator=(const end_ptr &a)
        {
            this->_type = a._type;
            return *this;
        }
        virtual char *execute(char *ptr){
            return  ptr;
        }
        virtual char   getName()
        {
            return _type;
        }
};

#endif