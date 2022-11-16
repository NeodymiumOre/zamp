#ifndef SET4LIBINTERFACE_HPP
#define SET4LIBINTERFACE_HPP

#include <map>
#include <memory>

#include "LibInterface.hpp"

class Set4LibInterfaces
{
    public:
        std::map<std::string, std::shared_ptr<LibInterface>> LibsCollection;

        Set4LibInterfaces() {};
        ~Set4LibInterfaces() {};
        void addLibInterface(std::string file);
};

#endif
