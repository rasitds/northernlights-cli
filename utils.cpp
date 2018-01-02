#include <iostream> // cout flush
void print(std::string text, std::string type = "none") {
    if (type == "response")
        std::cout << "> " << text << std::endl;
    else std::cout << text << std::endl;
}

void getPromptStyle(int type = 2) {
    switch (type) {
        case 0:
            std::cout << ">/ " << std::flush;
            break;
        case 1:
            std::cout << "> /" << std::flush;
            break;
        case 2:
            std::cout << "< /" << std::flush;
            break;
        case 3:
            std::cout << "</ " << std::flush;
            break;
        default:
            std::cout << "#  " << std::flush;
            break;
    }
}