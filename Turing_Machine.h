#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H
#include "constants.h"
#include "Stack.h"
#include <set>

class Turing_Machine
{
public:
    explicit Turing_Machine(std::istream& file);
    bool accepts(const std::string& word) const;
private:
	//std::map<state_name, std::map<symbol, std::tuple(state_name, symbol, bool)>>
    std::map<state_name, state> states;
    std::set<state_name> final_states;
    state_name start;
};


#endif
