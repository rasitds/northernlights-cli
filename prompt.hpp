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
        
        print("You typed: " + input, "response");
        getPromptStyle();
    }
}