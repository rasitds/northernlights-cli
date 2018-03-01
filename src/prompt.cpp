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

        if (input == "q")
            break;
        else if (input == "/") {
            setPromptStyle(4);
            getPromptStyle();
            continue;
        }

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
            std::string stringParams = getParameters(commandParams);

            print("info", "MISSING PARAMETERS. PARAMETERS ARE " + stringParams);

            getPromptStyle();
            continue;
        } else {
            bool checkParams = true;
            std::queue<std::string> _parameters = parameters;

            for (int j = 0; j < commandParams.size(); j++) {
                if (_parameters.front() == commandParams[j]) {
                    checkParams = true;
                    
                    _parameters.pop();
                } else
                    checkParams = false;
            }

            if (!checkParams) {
                std::string stringParams = getParameters(commandParams);

                print("warning", "INVALID PARAMETERS. PARAMETERS ARE " + stringParams);

                getPromptStyle();
                continue;
            }
        }

        command->second.function(parameters);
        
        getPromptStyle();
        fflush(stdout);
    }
}

void Prompt::setPromptStyle(int styleId) {
    this->m_ipromptStyle = styleId;
}

void Prompt::getPromptStyle() {
    switch (this->m_ipromptStyle) {
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
            std::cout << "# " << std::flush;
            break;
    }
}