#include <iostream>
#include "prompt.hpp"

int main() {
    Prompt prompt;
    
    print("Northern Lights CLI");
    prompt.init();
    prompt.get();
}