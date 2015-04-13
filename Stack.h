#ifndef STACK_H
#define STACK_H
#include "constants.h"
#include <list>

//stack that holds infinitely many blanks and prints in different orders


class Stack
{
    public:
    	explicit Stack(const bool& reverse);
        void push(const input& next);
        input pop();
        
        friend std::ostream& operator<<(std::ostream& out, const Stack& s)
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
        }

    private:
        std::list<input> stack;
        const bool PRINT_REVERSED;
};

#endif // STACK_H
