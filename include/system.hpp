#include "prompt.hpp"

class System : public Prompt {

private:
    int bootMode = 10;

public:
    void setBootMode(int);
    int getBootMode();
    void boot();

};