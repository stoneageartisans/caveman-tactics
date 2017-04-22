/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Enumerations
enum Process
{
    NONE,
    SHOW_TITLE_SCREEN,
    SHOW_MAIN_MENU
};

// Colors                          A    R    G    B
#define COLOR_TRANSPARENT SColor(  0,   0,   0,   0)
#define COLOR_BLACK       SColor(255,   0,   0,   0)
#define COLOR_WHITE       SColor(255, 255, 255, 255)
#define COLOR_RED         SColor(255, 255,   0,   0)
#define COLOR_ORANGE      SColor(255, 255, 127,   0)
#define COLOR_YELLOW      SColor(255, 255, 255,   0)
#define COLOR_GREEN       SColor(255,   0, 255,   0)
#define COLOR_BLUE        SColor(255,   0,   0, 255)
#define COLOR_PURPLE      SColor(255, 127,   0, 255)
#define COLOR_PINK        SColor(255, 255,   0, 255)
#define COLOR_GRAY        SColor(255, 127, 127, 127)
#define COLOR_DKGRAY      SColor(255,  63,  63,  63)
#define COLOR_BROWN       SColor(255, 115,  71,  47)
#define COLOR_MATGRAY     SColor(255,  89,  87,  91)
#define COLOR_MAT         SColor(255, 183, 160, 125)
#define COLOR_DEVGRAY     SColor(255,  55,  57,  54)

// Files
#define FILE_RESOURCES    "resources.zip"
#define FILE_SETTINGS     "data/settings.dat"

// Graphics Settings
#define FULLSCREEN        true
#define WINDOWED          false
#define BIT_DEPTH         32
#define WINDOW_CAPTION    L"Caveman Tactics"
#define COLOR_FORMAT      ECF_A8R8G8B8

// Grid Settings
#define TOTAL_HEXES       46

// Misc Settings
#define DELAY_SPLASH      2000

// Packed Files - Images
#define DEVELOPER_IMAGE   "images/developer_screen.png"
#define MOUSEMAP_IMAGE    "images/mousemap.png"
#define TITLE_IMAGE       "images/title_screen.png"
#define MENU_IMAGE        "images/menu_screen.png"
#define GAME_IMAGE        "images/game_screen.png"

// Packed Files - Meshes
#define DISPLAY_PLANE     "meshes/plane_1920x1200.3ds"
#define CHARACTER_PLANE   "meshes/plane_256x256.3ds"
#define OVERLAY_PLANE     "meshes/plane_256x256.3ds"

// Z Values
#define CHARACTER_Z       824.0
#define DISPLAY_PLANE_Z   CHARACTER_Z + 2.0
#define HEX_OVERLAY_Z     CHARACTER_Z + 1.0
#define MAX_Z             1000.0
#define TEXT_Z            CHARACTER_Z - 1.0
#define Z_OFFSET_1_250    199.0
#define Z_OFFSET_1_333    165.0
#define Z_OFFSET_1_600      0.0
#define Z_OFFSET_1_777      0.0

#endif /* CONSTANTS_H */
