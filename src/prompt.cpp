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
        else if (m_sinput == "/")
        {
            setPromptMode(1);
            printPromptStyle();
            continue;
        }

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
    this->m_ipromptMode = promptMode;
    /*switch (promptMode)
    {
    case 0:
    case 1:

    case 10:
        break;
    }

    setPromptStyle(-1);*/
}

int Prompt::getPromptMode()
{
    return this->m_ipromptMode;
}

void Prompt::setPromptStyle(int styleId)
{
    this->m_ipromptStyle = styleId;
}

int Prompt::getPromptStyle()
{
    return this->m_ipromptStyle;
}

void Prompt::printPromptStyle()
{
    switch (getPromptStyle())
    {
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