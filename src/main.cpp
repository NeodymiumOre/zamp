#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <filesystem>
#include <list>

#include "Interp4Command.hpp"
#include "MobileObj.hpp"
#include "LibInterface.hpp"
#include "Handlers.hpp"
#include "ProgramInterpreter.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  check_input_files(argc, argv);

  ProgramInterpreter interpreter;
  interpreter.cmdfile = argv[1];
  interpreter.xmlfile = argv[2];
  interpreter.xsdfile = "config/config.xsd";
  if(!interpreter.read_xml_file(interpreter.xmlfile));

  if(!interpreter.open_connection(interpreter.socket2serv))
    exit_app_with_msg("Trudne to...");
  else
    nprint("udalo sie");

}
