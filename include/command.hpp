#include <functional>
#include <unordered_map>
#include "db.hpp"

struct CommandStruct {
    std::string name;
    std::vector<std::string> params;
    std::function<void(std::queue<std::string>&)> function;
};
// auto_ptr unieuq_ptr, shared_ptr
class Command {

public:
    Command() {
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

    using MappedCommands = std::unordered_map<std::string, CommandStruct>;
    using MappedCommand = MappedCommands::value_type;

    MappedCommands all;

    void addCommand(CommandStruct command) {
        all.emplace(command.name, command);
    }
};