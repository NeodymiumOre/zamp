#ifndef  PROGRAMINTERPRETER_HPP
#define  PROGRAMINTERPRETER_HPP

#include <vector>
#include <sstream>
#include <list>
#include <thread>
#include <queue>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
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
#include "GuardedSocket.hpp"
// #include "Sender.hpp"

#define STATES_NUMBER 8

using namespace std;

class ProgramInterpreter
{    
    public:
        string cmdfile;
        string xmlfile;
        string xsdfile;
        GuardedSocket socket2serv;
        Scene _Scene;
        Set4LibInterfaces _LibSet;
        Configuration *Config;
        // Sender _Sender;

        ProgramInterpreter() {Config = new Configuration;}
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