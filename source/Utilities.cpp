/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Utilities.h"

#include <cstdlib>
#include <time.h>

/******************
 * Public Methods *
 ******************/

// Constructor
Utilities::Utilities()
{
    initialize();
}

// Destructor
Utilities::~Utilities()
{
    dispose();
}

// Returns the highger of 3 signed integers
s32 Utilities::get_highest_of_3( s32 VALUE1, s32 VALUE2, s32 VALUE3 )
{
    if( VALUE1 > VALUE2 )
    {
        if( VALUE1 > VALUE3 )
        {
            return VALUE1;
        }
        else
        {
            return VALUE3;
        }
    }
    else
    {
        if( VALUE2 > VALUE3 )
        {
            return VALUE2;
        }
        else
        {
            return VALUE3;
        }
    }
}

// Returns a random number from LOWEST to HIGHEST (inclusive)
s32 Utilities::get_random( s32 LOWEST, s32 HIGHEST )
{
    return ( rand() % ( HIGHEST - LOWEST + 1 ) ) + LOWEST;
}

/*******************
 * Private Methods *
 *******************/

void Utilities::dispose()
{
    // TODO
}

void Utilities::initialize()
{
    srand( time( NULL ) );
}
