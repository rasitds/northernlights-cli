#include <iostream>
#include <string>
#include <queue>
#include "prompt.hpp"
#include "utils.hpp"

void Prompt::init()
{
    print("system", "INIT: PROMPT");
    printPromptStyle();
}

void Prompt::get()
{
    while (getline(std::cin, m_sinput))
    {
        if (m_sinput.empty())
        {
            printPromptStyle();
            continue;
        }

        if (m_sinput == "q")
            trigger->terminate();

        std::queue<std::string> parameters = split(m_sinput);

        MappedCommands::iterator command = all.find(parameters.front());

        if (command == all.end())
        {
            print("response", "COMMAND NOT FOUND.");
            printPromptStyle();
            continue;
        }

        parameters.pop();

        const std::vector<std::string> commandParams = command->second.params;
        if (parameters.size() < commandParams.size())
        {
            std::string stringParams = getParameters(commandParams);

            print("info", "MISSING PARAMETERS. PARAMETERS ARE " + stringParams);

            printPromptStyle();
            continue;
        }
        else
        {
            bool checkParams = true;
            std::queue<std::string> _parameters = parameters;

            for (int j = 0; j < commandParams.size(); j++)
            {
                if (_parameters.front() == commandParams[j])
                {
                    checkParams = true;

                    _parameters.pop();
                }
                else
                    checkParams = false;
            }

            if (!checkParams)
            {
                std::string stringParams = getParameters(commandParams);

                print("warning", "INVALID PARAMETERS. PARAMETERS ARE " + stringParams);

                printPromptStyle();
                continue;
            }
        }

        command->second.function(parameters);

        printPromptStyle();
        fflush(stdout);
    }
}

void Prompt::setPromptMode(int promptMode)
{
    this->m_iPromptMode = promptMode;
}

int Prompt::getPromptMode()
{
    return this->m_iPromptMode;
}

void Prompt::printPromptStyle()
{
    int promptMode = Instance().getPromptMode();
    int promptStyleId = promptMode * 10;
    
    switch (promptStyleId)
    {
    case 0:
        std::cout << ">/ " << std::flush;
        break;
    case 10:
        std::cout << "> /" << std::flush;
        break;
    case 20:
        std::cout << "< /" << std::flush;
        break;
    case 40:
        std::cout << "</ " << std::flush;
        break;
    case 80:
        std::cout << "# " << std::flush;
        break;
    default:
        std::cout << "#<-" << std::flush;
        break;
    }
}