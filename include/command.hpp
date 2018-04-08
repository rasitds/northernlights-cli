#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_map>

class System;

struct CommandStruct
{
    std::string name;
    std::vector<std::string> params;
    std::function<void(std::queue<std::string> &)> function;
};
// auto_ptr unieuq_ptr, shared_ptr
class Command
{

public:
    using MappedCommands = std::unordered_map<std::string, CommandStruct>;
    using MappedCommand = MappedCommands::value_type;

    MappedCommands all;

    Command();

    void getCommands()
    {
        this->all = all;
    }

    void addCommand(CommandStruct command);

    std::string getParameters(const std::vector<std::string>);
};

#endif