#include <queue>
#include <functional>
#include "utils.hpp"

class Prompt {
    std::string input;

public:
    void init();
    void get();
};

void Prompt::init() {
    print("INIT: PROMPT");
    getPromptStyle();
}

void Prompt::get() {
    while(getline(std::cin, input)) {
        if (input.empty()) {
            getPromptStyle();
            continue;
        }

        if (input == "q" || input == "/")
            break;

        std::queue<std::string> parameters = split(input);

        std::cout << parameters.size();
        
        print("You typed: " + input, "response");
        getPromptStyle();
    }
}