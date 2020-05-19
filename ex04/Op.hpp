#ifndef ADD_HPP
#define ADD_HPP

#include <list>
#include <string>
#include "Token.hpp"

class Op : public Token
{
    private:
        std::string _name;
        std::string _type;
    public:
        Op(std::string name): _name("ope"), _type(name) {}
        virtual std::list<int> *execute(std::list<int> *list) 
        {
            int i = list->front();
            list->pop_front();
            int j = list->front();
            list->pop_front();
            if (_type == "+")
                list->push_front(i + j);
            else if (_type == "-")
                list->push_front(j - i);
            else if (_type == "*")
                list->push_front(i * j);
            else if (_type == "/")
                list->push_front(j / i);
            return list;
        }
        virtual std::list<Token *> *postfix(std::list<Token *> *list){
            Token *tmp = list->front();
            list->pop_front();
            Token *tmp2 = list->front();
            list->pop_front();
            list->push_front(tmp);
            list->push_front(tmp2);
            return list;
        }
                virtual std::string getName() {
            return _name;
        }
                        virtual std::string getType() {
            return _type;
        }
};

#endif