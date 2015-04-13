#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <map>

typedef char input;
typedef std::string state_name;
typedef std::tuple<state_name, input, bool> transition;
typedef std::map<input, transition> state;

const input BLANK='\\';
const char LEFT = 'L';
const char RIGHT = 'R';

#endif // CONSTANTS_H
