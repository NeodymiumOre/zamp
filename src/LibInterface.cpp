#include "LibInterface.hpp"
#include "Handlers.hpp"

// loading library with given name
LibInterface::LibInterface(const char *lib_name, RTLD_mode mode)
{
    void *lib_handler = dlopen(lib_name, mode);
    _lib_handler[lib_name] = lib_handler;
    if (!_lib_handler[lib_name])
        exit_app_with_msg("Library not found: " + *lib_name);
}

LibInterface::~LibInterface()
{
    for (auto it = _lib_handler.begin(); it != _lib_handler.end(); ++it)
        dlclose(it->second);
}

void LibInterface::CreateCmd(const std::string &cmd_name)
{
    void *pFun = dlsym(_lib_handler[cmd_name], "CreateCmd");
    if (!pFun)
        exit_app_with_msg("Function not found: CreateCmd");

    _pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);
    _pCmd = _pCreateCmd();
    _cmd_name = _pCmd->Getcmd_name();
}

std::string LibInterface::getcmd_name()
{
    return _cmd_name;
}

const Interp4Command* LibInterface::getCmd() const
{
    return _pCmd;
}