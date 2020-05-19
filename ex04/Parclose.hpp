#ifndef PARCLOSE_HPP
#define PARCLOSE_HPP

#include <list>

class Parclose : public Token
{
    private:
        std::string _name;
    public:
        Parclose() : _name(")") {}
        virtual std::list<int> *execute(std::list<int> *list) {
            return list;
        }
    virtual std::list<Token *> *postfix(std::list<Token *> *list){
        list->pop_front();
        Token *tmp = list->back();
        list->pop_back();
        list->push_front(tmp);
        
        return list;
    }
        virtual std::string getName() {
            return _name;
        }
        virtual std::string getType() {
            return "ParClose";
        }
};

#endif