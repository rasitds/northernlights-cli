#include "command.hpp"

class Prompt : public Command {
    std::string input;

public:
    void init();
    void get();
};