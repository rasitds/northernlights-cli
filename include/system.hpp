#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include "prompt.hpp"

class System : public Prompt
{

private:
    int m_ibootMode = 10;

public:
    void setBootMode(int bootMode);
    int getBootMode();
    void boot();
};

#endif