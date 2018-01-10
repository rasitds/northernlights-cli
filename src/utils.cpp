#include <iostream> // cout flush
#include <queue>
#include "lib/termcolor/termcolor.hpp"

void print(std::string text, std::string type = "none") {
    if (type == "response")
        std::cout << "> " << text << std::endl;
    else if (type == "warn")
        std::cout << termcolor::on_red << termcolor::dark << " " << text << " " << termcolor::reset << std::endl;
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

std::queue<std::string> split(const std::string& s) {
    std::queue<std::string> out;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(" ", pos)) != std::string::npos) {
        std::string substring(s.substr(prev_pos, pos-prev_pos));

        out.push(substring);
        
        prev_pos = ++pos;
    }

    out.push(s.substr(prev_pos, pos-prev_pos));

    return out;
}