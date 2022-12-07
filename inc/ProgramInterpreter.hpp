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
// #include "Sender.hpp"

#define STATES_NUMBER 8

using std::cout;
using std::endl;
using std::string;

class ProgramInterpreter
{    
    public:
        string cmdfile;
        string xmlfile;
        string xsdfile;
        int socket2serv;
        Scene _Scene;
        Set4LibInterfaces _LibSet;
        Configuration Config;
        // Sender _Sender;

        ProgramInterpreter() {Config = new Configuration;};
        ~ProgramInterpreter() {};

        void loadLibraries();
        void printLoadedLibs();
        bool read_xml_file(string xmlfile);
        bool open_connection(int &socket_nr);
        int send(int Sk2Server, const char *msg);
        bool exec_program(const char *filename);
        bool send_scene_state_2_server();

        


};




#endif