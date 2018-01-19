#include <iostream>
#include <queue>
#include "prompt.hpp"
#include "utils.hpp"

int main() {
    print("Northern Lights CLI");

    Prompt prompt;

    prompt.init();
    prompt.get();
}