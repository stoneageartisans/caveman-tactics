/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Utilities.h"

class Application
{
    public:
        Application();
        ~Application();
        void exit();
        void run();
        
    private:
        Utilities* utilities;
        
        void dispose();
        void initialize();
};

#endif /* APPLICATION_H */

