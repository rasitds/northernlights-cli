#include "system.hpp"
#include "db.hpp"

void System::boot(int bootMode) {
    switch (bootMode) {
        case 0:
        case 1:
            break;
        case 10:
            DB::getInstance().init();

            Prompt::init();
            Prompt::get();
    }
}