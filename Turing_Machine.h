#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H
#include "constants.h"
#include <map>
#include <set>

class Turing_Machine
{
public:
    
private:
    std::map<state_name, state> states;
    std::set<state_name> accepting;
    Stack left;
    Stack right;
    input head;
};


#endif
