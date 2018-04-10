#ifndef _TRIGGER_HPP_
#define _TRIGGER_HPP_

class Trigger {

public:
    static Trigger& Instance() {
        static Trigger m_Instance;
        return m_Instance;
    }
    void terminate();
    void exterminate();
};

#endif