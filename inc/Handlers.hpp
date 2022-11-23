#include <string>
#include <cstdio>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>

#include "Interp4Command.hpp"

#define LINE_SIZE 500
#define PORT 6217

void exit_app_with_msg(std::string msg);

void print(std::string text);

void nprint(std::string text);

void check_input_files(int argc, char *argv[]);

std::list<std::string> exec_preprocessor(const char *filename);

std::list<Interp4Command> create_cmd_list(std::list<std::string> cmd_lines);
