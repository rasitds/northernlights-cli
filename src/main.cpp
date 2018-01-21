#include <iostream>
#include <queue>
#include "prompt.hpp"
#include "db.hpp"
#include "utils.hpp"

int main() {
    print("Northern Lights CLI");

    Prompt prompt;
    
    DB::getInstance().init();
    
    prompt.init();
    prompt.get();
}