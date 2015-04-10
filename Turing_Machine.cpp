#include "Turing_Machine.h"


Turing_Machine::Turing_Machine(std::istream& file)
{
    
}

bool Turing_Machine::accepts(const std::string& word)
{
    //push word on the right stack in reverse order
    for(const auto& ch : word)
    {
        left.push(ch);
    }
    for(const auto& ch : word)
    {
        right.push(left.pop());
    }
    
    //head reads the first symbol
    head = right.pop();
    
    return false;
}
