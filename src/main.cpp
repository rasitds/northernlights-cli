#include <iostream>
#include <queue>
#include "utils.hpp"
#include "prompt.hpp"

int main() {
    print("Northern Lights CLI");

    Prompt prompt;

    prompt.init();
    prompt.get();
}