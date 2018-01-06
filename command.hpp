#include <functional>
#include <unordered_map>

struct CommandStruct {
    std::string name;
    std::vector<std::string> params;
};

class Command {
    using MappedCommands = std::unordered_map<std::string, CommandStruct>;

    using MappedCommand = MappedCommands::value_type;

    static MappedCommands all;

    static void addCommand(CommandStruct command) {
        all.emplace(command.name, command);
    }
};