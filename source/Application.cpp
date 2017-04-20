/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Application.h"

/* Public Methods */

// Constructor
Application::Application()
{
    initialize();
}

// Destructor
Application::~Application()
{
    dispose();
}

void Application::exit()
{
    // TODO
}

void Application::run()
{
    // TDOD
}

/* Private Methods */

void Application::dispose()
{
    delete utilities;
}

void Application::initialize()
{
    utilities = new Utilities();
}