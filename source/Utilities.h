/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <irrlicht.h>

using namespace irr;

class Utilities
{
    public:
        static s32 get_highest_of_3( s32 VALUE1, s32 VALUE2, s32 VALUE3 );
        static s32 get_random( s32 LOWEST, s32 HIGHEST );
};

#endif /* UTILITIES_H */
