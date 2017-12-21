//
// Created by chaosmyth on 12/12/2017.
//

#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H


#include "Vector.h"

using namespace std;

template <typename T>
class Stack: public Vector<T>
{
public:
    void push(T const& e) { this->push_back(e); }
    T pop() { return this->remove(this->size() - 1); }
    T& top() { return this->operator[](this->size() - 1); }
    bool empty() {return this->size()== 0;}
};

#endif //CALCULATOR_STACK_H
