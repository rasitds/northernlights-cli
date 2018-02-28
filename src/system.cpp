#include <iostream>
#include "system.hpp"
#include "db.hpp"

void System::setBootMode(int bootMode) {
    this->bootMode = bootMode;
}

int System::getBootMode() {
    return this->bootMode;
}

void System::boot() {
    switch (getBootMode()) {
        case 0: {
                std::string nlString = "Northern Lights";
                std::cout << &nlString << std::endl;
            }
        case 1:
        case 10:
            DB::getInstance().init();

            Prompt::init();
            Prompt::get();
    }
}