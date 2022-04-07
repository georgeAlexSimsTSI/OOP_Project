#ifndef APP_H
#define APP_H

#include "system.h"
#include "userInput.h"

class app{
    private:
        uniSystem sys;
    public:
    app();
    app(uniSystem &sys);
    void run();
};

#endif