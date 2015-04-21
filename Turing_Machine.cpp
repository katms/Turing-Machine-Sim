#include "Turing_Machine.h"
#include <stdexcept> //out_of_range
#include "exceptions.h"
#include <sstream>
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

    std::string current, next;
    char direction;
    symbol read, write;  
                  
    //read transition table
    while(!file.eof())
    {

        file >> current >> read >> next >> write >> direction;
        
        const transition tuple = std::make_tuple(next, write, (LEFT==direction));

        //make sure this isn't getting overwritten
        const auto on_current = states.find(current);
        if(on_current!=states.end())
        {
            const auto transitions = on_current->second;
            const auto on_read = transitions.find(read);
            if(on_read!=transitions.end() && on_read->second != tuple) //ignore if duplicate
            {
                state_name first_next;
                symbol first_write;
                char first_direction = (std::get<2>(on_read->second)) ? LEFT:RIGHT;
                std::tie(first_next, first_write, std::ignore) = on_read->second;
                throw Multiple_Paths(current, read, first_next, first_write, first_direction, current, read, next, write, direction);
            }
        }
        
        states[current][read] = tuple;
    }
}

bool Turing_Machine::accepts(const std::string& word) const
{
    Stack left(false);
    Stack right(true);
    symbol head;
    
    //push word on the right stack in reverse order
    for(auto itr = word.crbegin(); itr!=word.crend(); ++itr)
    {
        right.push(*itr);
    }
    
    //head reads the first symbol, now at the top of the right stack
    head = right.pop();
    state_name current = start;
    
    state_name next;
    symbol write;
    bool go_left;
    
    while(final_states.find(current)==final_states.end())
    {
        //output status
        std::cout<<left<<current<<head<<right<<std::endl;
               
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

        //determine which direction to go on the tape
        Stack& push = (go_left) ? right : left;
        Stack& pop = ((&push)==(&left)) ? right : left;

        push.push(write);
        head = pop.pop();
    }
    
    return true;
}
