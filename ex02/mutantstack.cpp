#include "mutantstack.hpp"

template <typename T>

MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &a)
        {
            this->c = a.c.copy();
            return *this;
        }
