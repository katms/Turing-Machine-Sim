#include "constants.h"
#include "Turing_Machine.h"
#include "exceptions.h"

int main(int argc, char* argv[])
{
    if(2>argc)
    {
        std::cout<<"Usage: tmsim <file> [words]"<<std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if(!file.is_open())
    {
        std::cerr<<"Could not open "<<argv[1]<<std::endl;
        return 1;
    }
    try
    {
        Turing_Machine tm(file);
        file.close();
    
        for(int word=2; word<argc; ++word)
        {
            std::cout<<(tm.accepts(argv[word]) ? "true" : "false")<<"\n\n";
        }
    }
    catch (TMSim_Exception& e)
    {
        std::cout<<e.what()<<std::endl;
        file.close();
        return 1;
    }

    return 0;
}
