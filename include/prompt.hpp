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

        const std::vector<std::string> commandParams = command->second.params;
        if(parameters.size() < commandParams.size()) {
            std::string stringParams;
            for (int j = 0; j < commandParams.size(); j++) {
                stringParams += commandParams[j];

                if (j < commandParams.size() - 1)
                    stringParams += ", ";
            }

            print("INVALID PARAMETERS. PARAMETERS ARE " + stringParams, "info");

            getPromptStyle();
            continue;
        }

        command->second.function(parameters);
        
        getPromptStyle();
    }
}