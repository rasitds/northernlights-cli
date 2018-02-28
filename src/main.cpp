#include <iostream>
#include <queue>
#include "system.hpp"
#include "utils.hpp"

int main() {
    print("system", "Northern Lights CLI");
    System system;
    system.setBootMode(0);
    system.boot();
}