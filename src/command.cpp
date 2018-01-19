#include "command.hpp"
#include "db.hpp"
#include "utils.hpp"

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
}

void Command::addCommand(CommandStruct command) {
    all.emplace(command.name, command);
}