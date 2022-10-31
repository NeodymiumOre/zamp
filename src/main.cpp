#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <filesystem>
#include <list>
#include "Interp4Command.hpp"
#include "MobileObj.hpp"
#include "LibInterface.hpp"
#include "Handlers.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  LibInterface lib_move("Interp4Move.so", lazy);
  lib_move.create_cmd("Interp4Move.so");
  cout << lib_move.get_cmd_name() << endl;

  LibInterface lib_set("Interp4Set.so", lazy);
  lib_set.create_cmd("Interp4Set.so");
  cout << lib_set.get_cmd_name() << endl;

  LibInterface lib_rotate("Interp4Rotate.so", lazy);
  lib_rotate.create_cmd("Interp4Rotate.so");
  cout << lib_rotate.get_cmd_name() << endl;

  LibInterface lib_pause("Interp4Pause.so", lazy);
  lib_pause.create_cmd("Interp4Pause.so");
  cout << lib_pause.get_cmd_name() << endl;




  check_input_files(argc, argv);
  std::list<string> cmd_lines = exec_preprocessor(argv[1]);
  std::list<Interp4Command> cmd_list = create_cmd_list(cmd_lines);

}
