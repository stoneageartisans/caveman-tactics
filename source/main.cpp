/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Application.h"

int main()
{
    Application* app = new Application;
    
    app->run();
    
    delete app;
    
    return 0;
}