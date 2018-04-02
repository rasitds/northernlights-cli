#ifndef _PROMPT_HPP_
#define _PROMPT_HPP_

#include "command.hpp"
#include "trigger.hpp"

class Prompt : public Command
{
    Trigger *trigger;

private:
    int m_ipromptMode = 10;
    int m_ipromptStyle = 2;
    std::string m_sinput;

public:
    void init();
    void get();

    void setPromptMode(int promptMode);
    void setPromptStyle(int styleId);

    int getPromptMode();
    int getPromptStyle();

    void printPromptStyle();
};

#endif