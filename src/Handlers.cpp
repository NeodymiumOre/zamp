#include <iostream>
#include <filesystem>
#include <string>
#include "Handlers.hpp"

void exit_app_with_msg(std::string msg)
{
  std::cout << msg << std::endl;
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
  std::string first_file_ext = "";
  std::filesystem::path second_file(argv[2]);
  std::string second_file_ext = "";

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

  std::cout << first_file_ext << " " << second_file_ext << std::endl;

  if(first_file_ext == second_file_ext)
    exit_app_with_msg("Both files have the same extension. Exiting app...");

  std::cout << "Both arguments are ok. Continue...";
}

bool exec_preprocessor(const char *filename, std::istringstream &IStrm4Cmds)
{
  std::string command = "cpp -P ";
  char line[LINE_SIZE];
  std::ostringstream OTmpStrm;

  command += filename;
  FILE* pProc = popen(command.c_str(), "r");
  if(!pProc) return false;
  while (fgets(line, LINE_SIZE, pProc))
    OTmpStrm << line;

  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}