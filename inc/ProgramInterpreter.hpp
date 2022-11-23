#ifndef  PROGRAMINTERPRETER_HPP
#define  PROGRAMINTERPRETER_HPP

#include <vector>
#include <sstream>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "xmlinterp.hpp"

#include "Scene.hpp"
#include "Set4LibInterfaces.hpp"
#include "Interp4Command.hpp"
#include "Configuration.hpp"
#include "Handlers.hpp"

using std::cout;
using std::endl;
using std::string;

class ProgramInterpreter
{
    private:
        Scene _Scene;
        Set4LibInterfaces _LibSet;
        Configuration _Config;
    
    public:
        string cmdfile;
        string xmlfile;
        string xsdfile;

        ProgramInterpreter() {};
        ~ProgramInterpreter() {};

        void loadLibraries();
        void printLoadedLibs();
        bool read_xml_file(string xmlfile);


};




#endif