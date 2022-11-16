#include "ProgramInterpreter.hpp"

void ProgramInterpreter::loadLibraries()
{
    _LibSet.addLibInterface("libInterp4Move.so");
    _LibSet.addLibInterface("libInterp4Set.so");
    _LibSet.addLibInterface("libInterp4Rotate.so");
    _LibSet.addLibInterface("libInterp4Pause.so");
}

void ProgramInterpreter::printLoadedLibs()
{
    cout << "Wczytane wtyczki:" << endl;
    for(auto &lib : _LibSet.LibsCollection)
        cout << lib.first << endl;

}