#include "constants.h"
#include "Turing_Machine.h"

int main(int argc, char* argv[])
{
    if(2!=argc)
    {
        std::cout<<"Usage: tmsim "<<std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if(!file.is_open())
    {
        std::cerr<<"Could not open "<<argv[1]<<std::endl;
        return 1;
    }
    Turing_Machine tm(file);
    file.close();
    tm.accepts("000111");
    
    return 0;
}
