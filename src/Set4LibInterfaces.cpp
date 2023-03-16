#include "Set4LibInterfaces.hpp"

using namespace std;

void Set4LibInterfaces::addLibInterface(string file)
{
    auto libPtr = make_shared<LibInterface>(file.c_str(), lazy);
    LibsCollection[file] = libPtr;
}

shared_ptr<LibInterface> Set4LibInterfaces::operator [](string Cmd)
{
  return LibsCollection[Cmd];
}