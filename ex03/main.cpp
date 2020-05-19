#include "Instructions.hpp"
#include "Ptr_inc.hpp"
#include "Ptr_dec.hpp"
#include "val_inc.hpp"
#include "val_dec.hpp"
#include "putchar.hpp"
#include "get_char.hpp"
#include "wh_ptr.hpp"
#include "end_ptr.hpp"
#include <iostream>
#include <fstream>
#include <errno.h>
#include <list>
#include <unistd.h>

std::list<Instructions *> *ft_delete(std::list<Instructions *> *list)
{
    std::list<Instructions *>::iterator tmp;
    int i = 0;
    for(tmp = list->begin(); (*tmp)->getName() != ']'; ++tmp)
    {
        if ((*tmp)->getName() == '[')
        {
                ++i;
                list->pop_front();
                list = ft_delete(list);
                tmp = list->begin();
        }
        list->pop_front();
    }
   list->pop_front();
    return list;
}

char *iter(char *ptr, std::list<Instructions *>::iterator it, int intra)
{        
    int i = 0;
    intra = 1;
    while (*ptr != 0 && ptr != 0)
    {
        std::list<Instructions *>::iterator tmp = it;
        for(tmp = it; (*tmp)->getName() != ']'; ++tmp)
        {
            if ((*tmp)->getName() == '[')
            {
                i++; // nombre d'intra boucle
                ptr = iter(ptr, ++tmp, 1);
                int j = 0;
                while (j < i)
                {
                    if ((*tmp)->getName() == ']')
                    {
                        j++;
                    }
                    tmp++;
                }
                i = 0;
            }
            ptr = (*tmp)->execute(ptr);
        }
    }
    return ptr;
}

int main(int argc, char *argv[])
{
    std::list<Instructions *> *list = new std::list<Instructions *>;
    if (argc < 2)
        std::cout << "Error : no filename" << std::endl;
    if (argc > 2)
    {
        std::cout << "Error : too many arguments" << std::endl;
        return 1;
    }
    std::ifstream inFlux(argv[1]);
    if (!inFlux)
    {
        std::cout << strerror(errno) << std::endl;
        return 1;
    }
    char c;
    char *ptr = new char;
    while(inFlux.get(c) && c != '\0')
    {
        if (c == '>')
        {
            Instructions* lala = new Ptr_inc();
            list->push_back(lala);   
        }
        else if (c == '<')
        {
            Instructions* lala = new Ptr_dec();
            list->push_back(lala);   
        }
        else if (c == '+')
        {
            Instructions* lala = new val_inc();
            list->push_back(lala);   
        }
        else if (c == '-')
        {
            Instructions* lala = new val_dec();
            list->push_back(lala);   
        }
        else if (c == '.')
        {
            Instructions* lala = new put_char();
            list->push_back(lala);   
        }
        else if (c == ',')
        {
            Instructions* lala = new get_char();
            list->push_back(lala);   
        }
        else if (c == '[')
        {
            Instructions* lala = new wh_ptr();
            list->push_back(lala);   
        }
        else if (c == ']')
        {
            Instructions* lala = new end_ptr();
            list->push_back(lala);   
        }
        else
        {
            if (c != '\0' && c != ' ' && c != '\n')
            {
                std::cout << "Type format error" << std::endl;
                return 2;
            }
        }
    }
    while (list->front())
    {
        std::list<Instructions *>::iterator it = list->begin();
        if (list->front()->getName() == '[')
        {
            ptr = iter(ptr, ++it, 1);
            list->pop_front();
            ft_delete(list);
            std::list<Instructions *>::iterator tmp;
        }
        else
        {
            ptr = list->front()->execute(ptr);
            list->pop_front();
        }
    }
}


