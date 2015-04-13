#ifndef STACK_H
#define STACK_H
#include "constants.h"
#include <list>

//stack that holds infinitely many blanks and prints in different orders


class Stack
{
    public:
        void push(const input& next);
        input pop();
        
        void print_from_bottom(std::ostream& out=std::cout) const;
        void print_from_top(std::ostream& out=std::cout) const;
    private:
        std::list<input> stack;
};

#endif // STACK_H
