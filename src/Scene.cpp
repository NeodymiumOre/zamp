#include "Scene.hpp"

void Scene::add_mobile_obj(Configuration *Config)
{
  for(unsigned long int i = 0; i < Config->GetVectorOfObjData().size(); ++i)
  {
    shared_ptr<MobileObj> tmp = make_shared<MobileObj>();
    
    tmp->SetPosition_m(Config->GetVectorOfObjData()[i].GetTrans());
    tmp->SetName(Config->GetVectorOfObjData()[i].GetName().c_str());
    tmp->SetAng_Yaw_deg(Config->GetVectorOfObjData()[i].GetRotXYZ()[2]);
    _mobileObjSet[tmp->GetName()] = tmp;
  }
}