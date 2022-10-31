#ifndef  SCENE_HHP
#define  SCENE_HHP

#include "MobileObj.hpp"

class Scene
{
    public:
        MobileObj *find_mobile_obj(std::string obj_name);
        void add_mobile_obj(MobileObj *mob_obj);
};

#endif
