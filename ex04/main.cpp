#include "Token.hpp"
#include <list>
#include <sstream>
#include <iostream>
#include "Num.hpp"
#include "Op.hpp"
#include "Parclose.hpp"
#include "Paropen.hpp"
#include <stack>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    std::stringstream ss;
        ss << argv[1];
    std::string *temp= new std::string[1000];
    std::list<Token *> *Took = new std::list<Token *>;
    std::list<int> *stack;
    stack = nullptr;
    int tmp;
    int j = 0;
    std::string ope;
    while (!ss.eof()) { 
        ss >> temp[j];
        if (temp[j].substr(0, 1) == "(")
        {
            Token* lala = new Paropen();
            Took->push_back(lala);
            std::string tmp = temp[j];
            temp[j] = tmp;
            temp[j] = tmp.substr(1, tmp.size() -1);
        }
        else if(temp[j] == "+" || temp[j] == "-" || temp[j] == "*" || temp[j] == "/")
        {
            Token *N = new Op(temp[j]);
            Took->push_back(N);
        }
        else if  (temp[j].substr(temp[j].size() - 1, 1) == ")")
        {
            temp[j] = temp[j].substr(0, temp[j].size() -1);
            std::stringstream(temp[j]) >> tmp;
            Token *N = new Num(tmp);
            Took->push_back(N);
            Token *lala = new Parclose();
            Took->push_back(lala);
            temp[j] = "";
        }
        if (std::stringstream(temp[j]) >> tmp)
        {
            Token *N = new Num(tmp);
            Took->push_back(N);
        }
        j++;
    }
    std::list<Token *> *post = new std::list<Token *>;
    std::list<Token *>::iterator it;
    std::list<Token *>::iterator lol;
    std::stack<Token *> *pile = new std::stack<Token *>;
    // Afficher Token
    std::cout << "Token: " ;
    for (it = Took->begin(); it != Took->end(); it++)
            std::cout << (*it)->getName() << "(" <<  (*it)->getType() << ")" <<" " ;
    std::cout << std::endl;
    for (it = Took->begin(); it != Took->end(); it++)
    {
        Token *nv = *it;
        if ((*it)->getName() == "num")
            post->push_back(nv);
        else if ((*it)->getName() == "ope")
        {
            if (!pile->empty())
            {
                while (!pile->empty() && pile->top()->getName() != "(")
                {
                    std::string pile_tmp = pile->top()->getType();
                    if ( pile_tmp != "" && ((*it)->getType() == "-" || (*it)->getType() == "+"))
                    {
                        post->push_back(pile->top());
                        pile->pop();
                    }
                }       
            }
            pile->push(nv);
        }
        else if ((*it)->getName() == "(")
            pile->push(nv);
        else if ((*it)->getName() == ")")
        {
            if (!pile->empty())
            {
                while (!pile->empty() && pile->top() && pile->top()->getName() != "(")
                {
                    post->push_back(pile->top());
                    pile->pop();
                }
                if (pile->top()->getName() == "(")
                    pile->pop();
            }
        }
    }
    while (!pile->empty())
    {
        post->push_back(pile->top());
        pile->pop();
    }
    // A presenter
    std::cout << "Postfix: ";
    for (lol = post->begin(); lol != post->end(); lol++)
    {
        std::cout << (*lol)->getName() << "(" << (*lol)->getType() << ")" << " ";
    }
    std::cout << std::endl;
    std::list<int> *calcul = new std::list<int>;
    std::cout << "Calcul" << std::endl;
    for (lol = post->begin(); lol != post->end(); lol++)
    {
        calcul = (*lol)->execute(calcul);
        std::cout << "I " << (*lol)->getName() << "(" << (*lol)->getType() << ")" << " | " << "OP ";
        if ((*lol)->getName() == "num")
            std::cout << "Push";
        else if ((*lol)->getType() == "*")
            std::cout << "Multiply";
        else if ((*lol)->getType() == "/")
            std::cout << "Divide";
        else if ((*lol)->getType() == "+")
            std::cout << "Add";
        else if ((*lol)->getType() == "-")
            std::cout << "Substract";
        std::cout << "| ST ";
        for (std::list<int>::iterator it = calcul->begin(); it != calcul->end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Result: " << calcul->front() << std::endl;
    return 0;
}