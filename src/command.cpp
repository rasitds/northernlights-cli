#include "command.hpp"
#include "db.hpp"
#include "utils.hpp"

Command::Command() {
    addCommand({ "cmds", {},
        [](std::queue<std::string>&) {
            print("system", "Command List: \n");

            //...
        }
    });
    addCommand({ "admin", {},
        [](std::queue<std::string>&) {
            print("warning", "ADMIN COMMAND EXECUTED.");
        }
    });
    addCommand({ "grant", {"access", "/"},
        [](std::queue<std::string>&) {
            print("warning", "GRANT COMMAND EXECUTED.");
        }
    });
    addCommand({ "clear", {},
        [](std::queue<std::string>&) {
            system("clear");
            print("success", "CLEAR COMMAND EXECUTED.");
        }
    });
    addCommand({ "echo", {"text"},
        [](std::queue<std::string>& params) {
            std::string text;

            for (int j = 0; j <= params.size() + 1; j++) {
                text += params.front() + " ";

                if (!params.empty())
                    params.pop();
            }

            text += params.back();

            print("system", text);
        }
    });
    addCommand({ "search", {"text | keyword"},
        [](std::queue<std::string>& params) {
            print("response", "Searching...");
            bool searchStatus = false;

            std::string text;

            for (int j = 0; j <= params.size() + 1; j++) {
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
        }
    });
    addCommand({ "analyze", {},
        [](std::queue<std::string>&) {
            print("response", "Analyzing...");
            bool resultFound = false;

            //...

            if (!resultFound)
                print("response", "NO RESULT FOUND.");
            else
                print("system", "Results:");

            //...
        }
    });
}

void Command::addCommand(CommandStruct command) {
    all.emplace(command.name, command);
}