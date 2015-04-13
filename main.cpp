#include "constants.h"
#include "Turing_Machine.h"

int main(int argc, char* argv[])
{
    if(2!=argc)
    {
        std::cout<<"Usage: tmsim <file>"<<std::endl;
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
    std::cout<<(tm.accepts("00011") ? "true" : "false")<<std::endl;
    std::cout<<(tm.accepts("000111") ? "true" : "false")<<std::endl;
    
    return 0;
}
