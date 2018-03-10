#include "command.hpp"

class Prompt : public Command
{
    int m_ipromptStyle = 2;
    std::string m_sinput;

public:
    void init();
    void get();
    void setPromptMode(int promptMode);
    void setPromptStyle(int styleId);
    int getPromptStyle();
    void printPromptStyle();
};