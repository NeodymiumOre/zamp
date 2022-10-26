#include <string>
#include <cstdio>

#define LINE_SIZE 500

void exit_app_with_msg(std::string msg);

void check_input_files(int argc, char *argv[]);

bool exec_preprocessor(const char *filename, std::istringstream &IStrm4Cmds);