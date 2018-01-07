#include <queue>
#include "command.hpp"

class Prompt : public Command {
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

        MappedCommands::iterator command = all.find(parameters.front());

        if (command == all.end()) {
            print("COMMAND NOT FOUND.", "response");
            getPromptStyle();
            continue;
        }

        parameters.pop();

        if(parameters.size() < command->second.params.size()) {
            print("Invalid parameters");
            getPromptStyle();
            continue;
        }

        command->second.function(parameters);
        
        getPromptStyle();
    }
}