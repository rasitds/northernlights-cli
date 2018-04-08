#include <iostream>
#include "system.hpp"
#include "trigger.hpp"
#include "db.hpp"

void System::setBootMode(int bootMode)
{
    this->m_ibootMode = bootMode;
}

int System::getBootMode()
{
    return this->m_ibootMode;
}

void System::boot()
{
    switch (getBootMode())
    {
    case 0:
        {
            std::string nlString = "Northern Lights";
            std::cout << &nlString << std::endl;
        }
    case 1:
    case 10:
        DB::getInstance().init();

        prompt.init();
        prompt.get();
        break;
    case 20:
        Trigger trigger;
        //trigger.terminate();
        //break;
    }
}