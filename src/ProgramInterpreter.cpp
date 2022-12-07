#include "ProgramInterpreter.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using namespace xercesc;

void ProgramInterpreter::loadLibraries()
{
    _LibSet.addLibInterface("libInterp4Move.so");
    _LibSet.addLibInterface("libInterp4Set.so");
    _LibSet.addLibInterface("libInterp4Rotate.so");
    _LibSet.addLibInterface("libInterp4Pause.so");
}

void ProgramInterpreter::printLoadedLibs()
{
    cout << "Wczytane wtyczki:" << endl;
    for(auto &lib : _LibSet.LibsCollection)
        cout << lib.first << endl;

}

bool ProgramInterpreter::read_xml_file(string xmlfile)
{
    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch(const XMLException &to_catch)
    {
        char *msg = XMLString::transcode(to_catch.getMessage());
        cerr << "Error during initialization: " << endl;
        cerr << msg << endl;
        XMLString::release(&msg);
        return 1;
    }

    SAX2XMLReader *parser = XMLReaderFactory::createXMLReader();

    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    parser->setFeature(XMLUni::fgXercesDynamic, false);
    parser->setFeature(XMLUni::fgXercesSchema, true);
    parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
    parser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

    DefaultHandler *handler = new XMLInterp4Config(_Config);
    parser->setContentHandler(handler);
    parser->setErrorHandler(handler);

    try
    {
        if(!parser->loadGrammar(xsdfile.c_str(), xercesc::Grammar::SchemaGrammarType, true))
            exit_app_with_msg("Cannot load grammar file!");
        
        parser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);
        parser->parse(xmlfile.c_str());
    }
    catch (const XMLException& Exception)
    {
        char *msg = XMLString::transcode(Exception.getMessage());
        cerr << msg << endl;
        XMLString::release(&msg);
        return false;
    }
    catch (const SAXParseException &Exception)
    {
        char *msg = XMLString::transcode(Exception.getMessage());
        char *file_id = xercesc::XMLString::transcode(Exception.getMessage());

        cerr << "Error:" << endl;
        cerr << "\t File: " << file_id << endl;
        cerr << "\t Line: " << Exception.getLineNumber() << endl;
        cerr << "\t Message: " << msg << endl;

        XMLString::release(&msg);
        XMLString::release(&file_id);
        return false;
    }
    catch (...)
    {
        cerr << "Undefined error occurred!" << endl;
        return false;
    }

    delete parser;
    delete handler;
    return true;
}

bool ProgramInterpreter::open_connection(int &socket_nr)
{
  struct sockaddr_in ServerAddrData;

  bzero((char *)&ServerAddrData, sizeof(ServerAddrData));

  ServerAddrData.sin_family = AF_INET;
  ServerAddrData.sin_addr.s_addr = inet_addr("127.0.0.1");
  ServerAddrData.sin_port = htons(PORT);

  socket_nr = socket(AF_INET, SOCK_STREAM, 0);

  if(socket_nr < 0)
  {
    cerr << "Socket opening error" << endl;
    return false;
  }
  
  if(connect(socket_nr, (struct sockaddr*)&ServerAddrData, sizeof(ServerAddrData)) < 0)
  {
    cerr << "Port connection error" << endl;
    return false;
  }

  return true;
}

int ProgramInterpreter::send(int Sk2Server, const char *sMesg)
{
  ssize_t  IlWyslanych;
  ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

  while ((IlWyslanych = write(Sk2Server,sMesg,IlDoWyslania)) > 0) {
    IlDoWyslania -= IlWyslanych;
    sMesg += IlWyslanych;
  }
  if (IlWyslanych < 0) {
    cerr << "*** Blad przeslania napisu." << endl;
  }
  return 0;
}

bool ProgramInterpreter::exec_program(const char *filename)
{
  std::string command = "cpp -P ";
  char line[LINE_SIZE];
  ostringstream ostr;
  istringstream istr;

  command += filename;
  FILE* file = popen(command.c_str(), "r");
  if(!file)
    exit(0);
  while (fgets(line, LINE_SIZE, file))
    ostr >> line;

  pclose(file);

  istr.str(ostr.str());
  queue<Interp4Command*> cmd;
  queue<std::thread> thread_set;
  string name;
  while(!istr.eof())
  {
    istr >> name;

    if(name == "Begin_Parallel_Actions") {}
    else if (name == "End_Parallel_Actions")
    {
      while(!cmd.empty())
      {
        thread_set.push(thread(&Interp4Command::ExecCmd, cmd.front(),&_Scene, &socket2serv));
        cmd.pop();
      }
      while(!thread_set.empty())
      {
        thread_set.front.join();
        thread_set.pop();
      }
    }
    else if(name == "Move" || name == "Rotate" || name == "Set" || name == "Pause")
    {
      cmd.push(_LibSet[name]->GetCmd());
      cmd.back()->ReadParams(istr);
    }
    return 1;
  }



  return cmd_list;
}