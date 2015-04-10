#ifndef STACK_H
#define STACK_H
#include "constants.h"
#include <list>

class Stack
{
    public:
        void push(const input& next);
        input pop();
        
        friend std::ostream& operator<<(std::ostream& out, const Stack& s);
    private:
        std::list<input> stack;
};

#endif // STACK_H
