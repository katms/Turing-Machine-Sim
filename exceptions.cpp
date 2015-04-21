#include "exceptions.h"

TMSim_Exception::TMSim_Exception(const std::string message):
		error_msg(message){}

Input_Error::Input_Error(state_name current, symbol read, state_name next, symbol write, char direction):
	TMSim_Exception("Format error reading transition:\n"+current+' '+read+' '+next+' '+write+' '+direction)
{}

Multiple_Paths::Multiple_Paths(state_name cur1, symbol read1, state_name next1, symbol write1, char dir1,
					state_name cur2, symbol read2, state_name next2, symbol write2, char dir2):
	TMSim_Exception("Transition "+cur1+' '+read1+' '+next1+' '+write1+' '+dir1+" conflicts with "+cur2+' '+read2+' '+next2+' '+write2+' '+dir2)
{}

