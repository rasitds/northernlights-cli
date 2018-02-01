#include <iostream>
#include <string>
#include <queue>
#include "prompt.hpp"
#include "utils.hpp"

void Prompt::init() {
    print("system", "INIT: PROMPT");
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
            print("response", "COMMAND NOT FOUND.");
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

            print("info", "INVALID PARAMETERS. PARAMETERS ARE " + stringParams);

            getPromptStyle();
            continue;
        }

        command->second.function(parameters);
        
        getPromptStyle();
    }
}