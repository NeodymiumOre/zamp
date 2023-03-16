#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "ObjData.hpp"

class Configuration
{
  private:
    vector<string> _vectorOfLibs;
    vector<ObjData> _vectorOfObjData;

  public:
    vector<string> &GetVectorOfLibs() { return _vectorOfLibs; }
    vector<ObjData> &GetVectorOfObjData() { return _vectorOfObjData; }
    void addLib(string name) { _vectorOfLibs.push_back(name); }
    void addObj(ObjData obj) { _vectorOfObjData.push_back(obj); }
};

#endif
