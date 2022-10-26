#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <filesystem>
#include "Interp4Command.hpp"
#include "MobileObj.hh"
#include "LibInterface.hpp"
#include "Handlers.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  LibInterface lib_move("Interp4Move.so", lazy);
  lib_move.CreateCmd("Interp4Move.so");
  cout << lib_move.getcmd_name() << endl;

  LibInterface lib_set("Interp4Set.so", lazy);
  lib_set.CreateCmd("Interp4Set.so");
  cout << lib_set.getcmd_name() << endl;

  LibInterface lib_rotate("Interp4Rotate.so", lazy);
  lib_rotate.CreateCmd("Interp4Rotate.so");
  cout << lib_rotate.getcmd_name() << endl;

  LibInterface lib_pause("Interp4Pause.so", lazy);
  lib_pause.CreateCmd("Interp4Pause.so");
  cout << lib_pause.getcmd_name() << endl;

  // cout << endl;
  // cout << pCmd->Getcmd_name() << endl;
  // cout << endl;
  // pCmd->PrintSyntax();
  // cout << endl;
  // pCmd->PrintCmd();
  // cout << endl;
  
  // delete pCmd;

  check_input_files(argc, argv);
}
