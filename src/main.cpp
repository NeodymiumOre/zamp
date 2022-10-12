#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <filesystem>
#include "Interp4Command.hh"
#include "MobileObj.hh"

using namespace std;

void exit_app_with_msg(string msg)
{
  cout << msg << endl;
  exit(0);
}

// check if right files were given
void check_input_files(int argc, char *argv[])
{
  // check if two files were given
  if(argc != 3)
    exit_app_with_msg("Invalid number of arguments were given. Exiting app...");

  // check if files with right extensions were given
  std::filesystem::path first_file(argv[1]);
  string first_file_ext = "";
  std::filesystem::path second_file(argv[2]);
  string second_file_ext = "";

  if(first_file.has_extension())
  {
      first_file_ext = first_file.extension().string();
      if(first_file_ext != ".cmd" and first_file_ext != ".xml")
        exit_app_with_msg("Invalid extension of first file. Exiting app...");
  }
  else
    exit_app_with_msg("First file has no extension. Exiting app...");

  if(second_file.has_extension())
  {
      second_file_ext = second_file.extension().string();
      if(second_file_ext != ".cmd" and second_file_ext != ".xml")
        exit_app_with_msg("Invalid extension of second file. Exiting app...");
  }
  else
    exit_app_with_msg("Second file has no extension. Exiting app...");

  cout << first_file_ext << " " << second_file_ext << endl;

  if(first_file_ext == second_file_ext)
    exit_app_with_msg("Both files have the same extension. Exiting app...");

  cout << "Both arguments are ok. Continue...";
}

int main(int argc, char *argv[])
{
  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  // pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  // Interp4Command *pCmd = pCreateCmd_Move();

  // cout << endl;
  // cout << pCmd->GetCmdName() << endl;
  // cout << endl;
  // pCmd->PrintSyntax();
  // cout << endl;
  // pCmd->PrintCmd();
  // cout << endl;
  
  // delete pCmd;

  dlclose(pLibHnd_Move);

  check_input_files(argc, argv);
}
