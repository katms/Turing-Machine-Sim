#include "Turing_Machine.h"

Turing_Machine::Turing_Machine(std::istream& file)
{
    //read start state
    file >> start;
    file.get(); //go to next line
    
    //read accepting states
    std::string final;
    while(file.peek()!='\n')
    {
        file >> final;
        final_states.insert(final);
    }
}

bool Turing_Machine::accepts(const std::string& word)
{
    //push word on the right stack in reverse order
    for(const auto& ch : word)
    {
        left.push(ch);
    }
    for(unsigned i=0; i<word.size(); ++i)
    {
        right.push(left.pop());
    }
    
    //head reads the first symbol, now at the top of the right stack
    head = right.pop();
    
    return false;
}
