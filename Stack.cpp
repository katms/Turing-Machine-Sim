#include "Stack.h"


void Stack::push(const input& next)
{
    if(!(stack.empty() && BLANK==next))
    {
        stack.push_back(next);
    }
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

void Stack::print_from_bottom(std::ostream& out) const
{
    for(const auto& item: stack)
    {
        out<<item;
    }
}

void Stack::print_from_top(std::ostream& out) const
{
    for(auto iter = stack.crbegin(); iter!=stack.crend(); ++iter)
    {
        out<<*iter;
    }
}