#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <list>

class Token 
{
    private:
     //   std::string _name;
    public:
       // std::string _type = "";
        virtual ~Token() {}
        virtual std::list<int> *execute(std::list<int> *list) = 0;
        virtual std::list<Token *> *postfix(std::list<Token *> *lst) = 0;
        virtual std::string getName() = 0;
        virtual std::string getType() =0;
};

#endif