#include "Stack.h"


void Stack::push(const input& next)
{
    stack.push_back(next);
}


input Stack::pop()
{
    if(stack.empty())
    {
        return BLANK;
    }
    else
    {
        input last=std::move(stack.back());
        stack.pop_back();
        return last;
    }
}


