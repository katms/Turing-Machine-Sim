#include "Turing_Machine.h"
#include <stdexcept> //out_of_range

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
    
    //read transition table
    std::string current, next;
    char direction;
    input read, write;
    while(!file.eof())
    {
        //current read next write direction
        file >> current >> read >> next >> write >> direction;
        states[current][read] = std::make_tuple(next, write, (LEFT==direction));
    }
}

bool Turing_Machine::accepts(const std::string& word)
{
    Stack left;
    Stack right;
    input head;
    
    //push word on the right stack in reverse order
    for(auto itr = word.crbegin(); itr!=word.crend(); ++itr)
    {
        right.push(*itr);
    }
    
    //head reads the first symbol, now at the top of the right stack
    head = right.pop();
    state_name current = start;
    
    state_name next;
    input write;
    bool go_left;
    
    while(final_states.find(current)==final_states.end())
    {
        //output status
        left.print_from_bottom();
        std::cout<<current<<head;
        right.print_from_top();
        std::cout<<std::endl;
        
        try
        {
            std::tie(next, write, go_left) = states.at(current).at(head);
        }
        
        //crash
        catch (std::out_of_range)
        {
            return false;
        }
        
        //transition
        current = next;
        if(go_left)
        {
            right.push(write);
            head = left.pop();
        }
        else
        {
            left.push(write);
            head = right.pop();
        }
    }
    
    return true;
}
