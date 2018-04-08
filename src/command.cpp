#include "command.hpp"
#include "user.hpp"
#include "db.hpp"
#include "utils.hpp"
#include "prompt.hpp"

Command::Command()
{
    
    addCommand({"cmds", {}, [](std::queue<std::string> &)
                {
                    print("system", "Command List: \n");

                    //...
                }});
    addCommand({"/", {}, [](std::queue<std::string> &)
                {
                    int promptMode = Prompt::Instance().getPromptMode();
                    Prompt::Instance().setPromptMode(promptMode == 2 ? 8 : 2);
                }});
    addCommand({"access", {}, [](std::queue<std::string> &)
                {
                    int promptMode = Prompt::Instance().getPromptMode();;
                    if (promptMode != 8)
                        return;

                    print("warning", "ACCESS COMMAND EXECUTED!");

                    //...
                }});
    addCommand({"admin", {}, [](std::queue<std::string> &)
                {
                    User user;
                    int userType = user.getUserType();
                    if (!userType)
                        print("warning", "ADMIN COMMAND EXECUTED.");
                }});
    addCommand({"grant", {"access", "/"}, [](std::queue<std::string> &)
                {
                    print("warning", "GRANT COMMAND EXECUTED.");
                }});
    addCommand({"clear", {}, [](std::queue<std::string> &)
                {
                    system("clear");
                    print("response", "CLEAR COMMAND EXECUTED.");
                }});
    addCommand({"echo", {"text"}, [](std::queue<std::string> &params)
                {
                    std::string text;

                    for (int j = 0; j <= params.size() + 1; j++)
                    {
                        text += params.front() + " ";

                        if (!params.empty())
                            params.pop();
                    }

                    text += params.back();

                    print("system", text);
                }});
    addCommand({"search", {"text | keyword"}, [](std::queue<std::string> &params)
                {
                    print("response", "Searching...");
                    bool searchStatus = false;

                    std::string text;

                    for (int j = 0; j <= params.size() + 1; j++)
                    {
                        text += params.front() + " ";

                        if (!params.empty())
                            params.pop();
                    }

                    text += params.back();

                    //...

                    if (!searchStatus)
                        print("response", "NO VALID SEARCH FOUND.");
                    else
                        print("system", "SHOWING RESULTS");
                }});
    addCommand({"analyze", {}, [](std::queue<std::string> &)
                {
                    print("response", "Analyzing...");
                    bool resultFound = false;

                    //...

                    if (!resultFound)
                        print("response", "NO RESULT FOUND.");
                    else
                        print("system", "Results:");

                    //...
                }});
}

void Command::addCommand(CommandStruct command)
{
    all.emplace(command.name, command);
}

std::string Command::getParameters(const std::vector<std::string> cmdParams)
{
    std::string stringParams;
    for (int j = 0; j < cmdParams.size(); j++)
    {
        stringParams += cmdParams[j];

        if (j < cmdParams.size() - 1)
            stringParams += ", ";
    }

    return stringParams;
}