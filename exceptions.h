#include <exception> //std::exception
#include "constants.h"

class TMSim_Exception
{
public:
	TMSim_Exception(const std::string message);
	const std::string what() const {return error_msg;}
protected:
	std::string error_msg;
};

class Input_Error : public TMSim_Exception
{
public:
	Input_Error(state_name current, symbol read, state_name next, symbol write, char direction);
};

class Multiple_Paths : public TMSim_Exception
{
public:
	Multiple_Paths(state_name cur1, symbol read1, state_name next1, symbol write1, char dir1,
					state_name cur2, symbol read2, state_name next2, symbol write2, char dir2);
};