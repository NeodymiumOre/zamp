#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <filesystem>
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "LibInterface.hpp"
#include "Handlers.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  LibInterface lib_move("libInterp4Move.so", lazy);
  lib_move.CreateCmd("libInterp4Move.so");
  cout << lib_move.getcmd_name() << endl;

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
