#ifndef  SCENE_HPP
#define  SCENE_HPP

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "MobileObj.hpp"
#include <map>
#include <memory>
#include "Configuration.hpp"

using namespace std;

class Scene
{
    private:
        map<string, shared_ptr<MobileObj>> _mobileObjSet;

    public:
        Scene() {}
        ~Scene() {}

        shared_ptr<MobileObj> find_mobile_obj(const char *sObjName) {  return _mobileObjSet[sObjName]; }
        shared_ptr<MobileObj> find_mobile_obj(const string &rObjName){   return _mobileObjSet[rObjName]; }
        shared_ptr<MobileObj> operator [] (string &name)  { return _mobileObjSet[name]; }
        shared_ptr<MobileObj> operator [] (char *name) {  return _mobileObjSet[name]; }

        void add_mobile_obj(Configuration *Config);
};

#endif
