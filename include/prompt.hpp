#ifndef _PROMPT_HPP_
#define _PROMPT_HPP_

#include "command.hpp"
#include "trigger.hpp"


class Prompt : public Command
{
    Trigger *trigger;

public:
    static Prompt& Instance() { 
        static Prompt m_Instance;
        return m_Instance;
    }

    void init();
    void get();

    void setPromptMode(int promptMode);

    int getPromptMode();

    void printPromptStyle();

private:
    int m_iPromptMode = 2;
    std::string m_sinput;
};

#endif