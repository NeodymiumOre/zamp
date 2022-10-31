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

void LibInterface::create_cmd(const std::string &cmd_name)
{
    void *pFun = dlsym(_lib_handler[cmd_name], "create_cmd");
    if (!pFun)
        exit_app_with_msg("Function not found: create_cmd");

    // get reference to function create_cmd
    _pcreate_cmd = *reinterpret_cast<Interp4Command* (**)(std::string)>(&pFun);
    // call create_cmd and save its return to _pCmd
    _pCmd = _pcreate_cmd("xd xd xd");
    // get name of command from returned object _pCmd
    _cmd_name = _pCmd->get_cmd_name();
}

std::string LibInterface::get_cmd_name()
{
    return _cmd_name;
}

const Interp4Command* LibInterface::getCmd() const
{
    return _pCmd;
}