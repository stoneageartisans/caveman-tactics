/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Logger.h"

#include <iostream>

/* Public Methods */

// Constructor
Logger::Logger()
{
    initialize();
}

// Destructor
Logger::~Logger()
{
    dispose();
}

void Logger::log( char* MESSAGE )
{
    std::cout << MESSAGE << std::endl;
}

/* Private Methods */

void Logger::dispose()
{
    // TDOD
}

void Logger::initialize()
{
    // TODO
}