#ifndef SET4LIBINTERFACE_HPP
#define SET4LIBINTERFACE_HPP

#include <map>
#include <memory>

#include "LibInterface.hpp"

using namespace std;

class Set4LibInterfaces
{
    public:
        map<string, shared_ptr<LibInterface>> LibsCollection;

        Set4LibInterfaces() {};
        ~Set4LibInterfaces() {};
        void addLibInterface(string file);
        shared_ptr<LibInterface> operator [] (string cmd);
};

#endif
