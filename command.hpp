#include <functional>
#include <unordered_map>

struct CommandStruct {
    std::string name;
    std::vector<std::string> params;
    std::function<void(std::queue<std::string>&)> function;
};

class Command {

public:
    Command() {
        addCommand({ "admin", {},
            [](std::queue<std::string>&) {
                print("ADMIN COMMAND EXECUTED", "response");
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