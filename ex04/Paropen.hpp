#ifndef PAROPEN_HPP
#define PAROPEN_HPP

#include <list>

class Paropen : public Token
{
    private:
        std::string _name;
    public:
        Paropen() : _name("(") {}
        virtual std::list<int> *execute(std::list<int> *list) {
            return list;
        }
        virtual std::list<Token *> *postfix(std::list<Token *> *lst)
        {
            lst->pop_front();
            Token *num = lst->front();
            lst->pop_front();
            Token *ope = lst->front();
            lst->pop_front();
            lst->push_back(ope);
            lst->push_front(num);
            return lst;
        };
            virtual std::string getName() {
            return _name;
        }
        virtual std::string getType() {
            return "ParOpen";
        }
};

#endif