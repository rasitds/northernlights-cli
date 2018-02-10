#include "command.hpp"

class Prompt : public Command {
    int promptStyle = 2;
    std::string input;

public:
    void init();
    void get();
    void setPromptStyle(int);
    void getPromptStyle();
};