#include <iostream>
#include <queue>
#include "utils.hpp"
#include "prompt.hpp"

int main() {
    Prompt prompt;

    print("Northern Lights CLI");
    prompt.init();
    prompt.get();
}