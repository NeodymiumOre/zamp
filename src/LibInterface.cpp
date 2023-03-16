#include "LibInterface.hpp"
#include "Handlers.hpp"

// loading library with given name
LibInterface::LibInterface(const char *lib_name, RTLD_mode mode)
{
    // _lib_handler = dlopen(lib_name, mode);
    _lib_handler = dlopen(lib_name, mode);
    if(!_lib_handler)
        exit_app_with_msg("Library not found: " + std::string(lib_name));
}

LibInterface::~LibInterface()
{
    dlclose(_lib_handler);
}

void LibInterface::create_cmd(const std::string &cmd_name)
{
    void *pFun = dlsym(_lib_handler, "create_cmd");
    if (!pFun)
        exit_app_with_msg("Function not found: create_cmd");

    // get reference to function create_cmd
    _pcreate_cmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);
    // call create_cmd and save its return to _pCmd
    _pCmd = _pcreate_cmd();
    // get name of command from returned object _pCmd
    _cmd_name = _pCmd->get_cmd_name();
}

std::string LibInterface::get_cmd_name()
{
    return _cmd_name;
}

Interp4Command* LibInterface::getCmd() const
{
    return _pcreate_cmd();
}