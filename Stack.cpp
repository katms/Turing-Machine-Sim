#include "Stack.h"

Stack::Stack(const bool& print_reversed):
    PRINT_REVERSED(print_reversed) {}

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

/*std::ostream& operator<<(std::ostream& out, const Stack& s)
{
    if(s.PRINT_REVERSED)
    {
    for(auto iter = s.stack.crbegin(); iter!=s.stack.crend(); ++iter)
        {
            out<<*iter;
        }
    }
    else
    {
        for(const auto& item: s.stack)
        {
            out<<item;
        }               
    }
    return out;
}*/