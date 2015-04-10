#include <iostream>
#include <tuple>

typedef char input;
typedef std::string state_name;
typedef std::tuple<state_name, input, bool> transition;
typedef std::map<input, transition> state;


const input BLANK='\\';
