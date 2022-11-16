#ifndef  PROGRAMINTERPRETER_HPP
#define  PROGRAMINTERPRETER_HPP

#include <vector>
#include <sstream>

#include "Scene.hpp"
#include "Set4LibInterfaces.hpp"
#include "Interp4Command.hpp"

using std::cout;
using std::endl;
using std::string;

class ProgramInterpreter
{
    private:
        Scene _Scene;
        Set4LibInterfaces _LibSet;
    
    public:
        ProgramInterpreter() {};
        ~ProgramInterpreter() {};

        void loadLibraries();
        void printLoadedLibs();

};




#endif