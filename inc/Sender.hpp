#ifndef SENDER_HH
#define SENDER_HH

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>
// #include "AccessControl.hh"
// #include "Port.hh"

class Sender {
    public:
        Sender(int Socket, Scene *pScn): _Socket(Socket), _pScn(pScn) {}
        bool ShouldCountinueLooping() const { return _ContinueLooping; }
        void CancelCountinueLooping() { _ContinueLooping = false; }
        void Watching_and_Sending();

    private:
        volatile bool _ContinueLooping = true;
        int _Socket = 0;
        Scene *_pScn = nullptr;
};

#endif
