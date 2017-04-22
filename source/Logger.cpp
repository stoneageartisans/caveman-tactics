/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Logger.h"

#include <iostream>

/******************
 * Public Methods *
 ******************/

void Logger::log( const char* MESSAGE )
{
    std::cout << MESSAGE << std::endl;
}
