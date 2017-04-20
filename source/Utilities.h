/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include "constants.h"

class Utilities
{
    public:
        Utilities( );
        ~Utilities( );
        s32 get_highest_of_3( s32 VALUE1, s32 VALUE2, s32 VALUE3 );
        s32 get_random( s32 LOWEST, s32 HIGHEST );
        
    private:
        void dispose();
        void initialize();
};

#endif /* UTILITIES_H */

