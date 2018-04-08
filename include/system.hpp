#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include "prompt.hpp"

class System
{

private:
    int m_ibootMode = 10;

public:
    Prompt prompt;
    void setBootMode(int bootMode);
    int getBootMode();
    void boot();
};

#endif