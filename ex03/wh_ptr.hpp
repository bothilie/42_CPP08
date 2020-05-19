#ifndef WH_PTR_HPP
#define WH_PTR_HPP

#include "Instructions.hpp"

class wh_ptr : public Instructions
{
    private:
    char _type;
    public:
        wh_ptr(){ _type = '[';}
        char    *_ptr;
        wh_ptr(char *ptr) {
            _ptr = ptr;
        }
        ~wh_ptr(){}
        wh_ptr(const wh_ptr &a): _type(a._type) {}
        wh_ptr &operator=(const wh_ptr &a)
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