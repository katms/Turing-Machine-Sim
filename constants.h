#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <map>

typedef char symbol;
typedef std::string state_name;
typedef std::tuple<state_name, symbol, bool> transition;
typedef std::map<symbol, transition> state;

const symbol BLANK='\\';
const char LEFT = 'L';
const char RIGHT = 'R';

#endif // CONSTANTS_H
