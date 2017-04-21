/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Colors
#define COLOR_TRANSPARENT       SColor(0, 0, 0, 0)
#define COLOR_BLACK             SColor(255, 0, 0, 0)
#define COLOR_WHITE             SColor(255, 255, 255, 255)
#define COLOR_RED               SColor(255, 255, 0, 0)
#define COLOR_ORANGE            SColor(255, 255, 127, 0)
#define COLOR_YELLOW            SColor(255, 255, 255, 0)
#define COLOR_GREEN             SColor(255, 0, 255, 0)
#define COLOR_BLUE              SColor(255, 0, 0, 255)
#define COLOR_PURPLE            SColor(255, 127, 0, 255)
#define COLOR_PINK              SColor(255, 255, 0, 255)
#define COLOR_GRAY              SColor(255, 127, 127, 127)
#define COLOR_DKGRAY            SColor(255, 63, 63, 63)
#define COLOR_BROWN             SColor(255, 115, 71, 47)
#define COLOR_MATGRAY           SColor(255, 89, 87, 91)
#define COLOR_MAT               SColor(255, 183, 160, 125)
#define COLOR_DEVGRAY           SColor(255, 55, 57, 54)

// Files
#define FILE_RESOURCES "resources.zip"
#define FILE_SETTINGS  "data/settings.dat"

// Graphics Settings
#define FULLSCREEN     true
#define WINDOWED       false
#define BIT_DEPTH      32
#define WINDOW_CAPTION L"Caveman Tactics"
#define COLOR_FORMAT   ECF_A8R8G8B8

#endif /* CONSTANTS_H */
