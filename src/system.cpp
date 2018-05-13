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
            int num = 1;
            std::string nlString = "Northern Lights";
            std::cout << &nlString << std::endl;
            for (int row = 1; row <= 7; row++) {
                for (int column = 0; column <= row; column++) {
                    num++;
                    std::cout << num << " ";
                }
                std::cout << row << "\n" << num << " ";
            }
        }
    case 1:
    case 10:
        DB::getInstance().init();
        DB::getInstance().test();

        prompt.init();
        prompt.get();
        break;
    case 20:
        Trigger trigger;
        //trigger.terminate();
        //break;
    }
}