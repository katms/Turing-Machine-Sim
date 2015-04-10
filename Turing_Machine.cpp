#include "Turing_Machine.h"


Turing_Machine::Turing_Machine(std::istream& file)
{
    //read states
    state_name next;
    if(file.peek()=='#') //skip comments
    {
        std::getline(file, next);
    }
    while(file.peek()!='\n')
    {
        file >> next;
        std::cout<<next<<' ';
        states[next];
    }
    std::cout<<std::endl;

    file.get();
    if(file.peek()=='#')
    {
        std::getline(file, next);
    }
    
    //read final states
    while(file.peek()!='\n')
    {
        file >> next;
        std::cout<<next<<' ';
        final_states.insert(next);
    }
    
    //read transitions
    
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
    
    //head reads the first symbol, now at the top of the right stack
    head = right.pop();
    
    return false;
}
