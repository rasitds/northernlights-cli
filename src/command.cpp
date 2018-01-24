#include "command.hpp"
#include "db.hpp"
#include "utils.hpp"
#include <iostream>
Command::Command() {
    addCommand({ "admin", {},
        [](std::queue<std::string>&) {
            print("ADMIN COMMAND EXECUTED.", "warn");
        }
    });
    addCommand({ "grant", {"access", "/"},
        [](std::queue<std::string>&) {
            print("GRANT COMMAND EXECUTED.", "warn");
        }
    });
    addCommand({ "clear", {},
        [](std::queue<std::string>&) {
            system("clear");
            print("CLEAR COMMAND EXECUTED.", "okay");
        }
    });
    addCommand({ "echo", {},
        [](std::queue<std::string>& params) {
            std::string text;

            for (int j = 0; j <= params.size() + 1; j++) {
                text += params.front() + " ";

                params.pop();
            }

            text += params.back();

            print(text);
        }
    });
}

void Command::addCommand(CommandStruct command) {
    all.emplace(command.name, command);
}