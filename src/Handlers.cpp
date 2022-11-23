#include <iostream>
#include <filesystem>
#include <string>
#include "Handlers.hpp"

#define XD std::cout << "XD" << std::endl;

void exit_app_with_msg(std::string msg)
{
  std::cout << msg << std::endl;
  exit(0);
}

void print(std::string text)
{
  std::cout << text;
}

void nprint(std::string text)
{
  std::cout << text << std::endl;
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

  std::cout << "Both arguments are ok. Continue..." << std::endl;
}

std::list<std::string> exec_preprocessor(const char *filename)
{
  std::string command = "cpp -P ";
  char line[LINE_SIZE];
  std::list<std::string> cmd_list;

  command += filename;
  FILE* file = popen(command.c_str(), "r");
  if(!file)
    exit(0);
  while (fgets(line, LINE_SIZE, file))
    cmd_list.push_back(line);

  pclose(file);

  return cmd_list;
}

std::list<Interp4Command> create_cmd_list(std::list<std::string> cmd_lines)
{
  for(auto line : cmd_lines)
  {
    if(line == "\n")
      print("xd");
    print(line);
  }
}
