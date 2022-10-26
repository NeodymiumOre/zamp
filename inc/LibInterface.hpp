#ifndef LIBINTERFACE_HPP
#define LIBINTERFACE_HPP

#include <string>
#include <dlfcn.h>
#include <map>

#include "Interp4Command.hpp"
#include "MobileObj.hh"

enum RTLD_mode {lazy = RTLD_LAZY,\
                now = RTLD_NOW,\
                binding_mask = RTLD_BINDING_MASK,\
                noload = RTLD_NOLOAD,\
                deepbind = RTLD_DEEPBIND};

class LibInterface
{
    private:
        std::map<std::string, void*> _lib_handler;
        std::string _cmd_name;
        Interp4Command *(*_pCreateCmd)(void);
        Interp4Command *_pCmd;
    public:
        LibInterface(const char *lib_name, RTLD_mode mode);
        ~LibInterface();

        void CreateCmd(const std::string &cmd_name);
        std::string getcmd_name();

        const Interp4Command* getCmd() const;
};


#endif