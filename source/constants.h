/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Enumerations
enum Process
{
    NO_PROCESS,
    FLASH_TEXT,
    SHOW_TITLE_SCREEN
};

enum Screen
{
    NO_SCREEN,
    TITLE,
    MAIN_MENU,
    GAME,
    CHARACTER,
    OPTIONS
};

// GUI Widgets
#define BUTTON_AGILITY_MINUS  10
#define BUTTON_AGILITY_PLUS   11
#define BUTTON_BRAINS_MINUS   20
#define BUTTON_BRAINS_PLUS    21
#define BUTTON_BRAWN_MINUS    30
#define BUTTON_BRAWN_PLUS     31
#define BUTTON_STAMINA_MINUS  40
#define BUTTON_STAMINA_PLUS   41
#define BUTTON_START         100
#define BUTTON_RESUME        110
#define BUTTON_OPTIONS       120
#define BUTTON_OPTIONS_DONE  121
#define BUTTON_EXIT          999
#define CHECKBOX_MUSIC       122

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
#define COLOR_DEVGRAY     SColor(255,  39,  39,  41)

// Files
#define FILE_MUSIC     "sound/music.mp3"
#define FILE_RESOURCES "resources.zip"
#define FILE_SETTINGS  "data/settings.dat"

// Graphics Settings
#define FULLSCREEN     true
#define WINDOWED       false
#define BIT_DEPTH      32
#define WINDOW_CAPTION L"Caveman Tactics"
#define COLOR_FORMAT   ECF_A8R8G8B8

// Grid Settings
#define TOTAL_HEXES 46

// Misc Settings
#define DELAY_SPLASH     2500
#define DELAY_TEXT_FLASH  500
#define LIGHT_RADIUS     3000
#define SMALL               0
#define MEDIUM              1
#define LARGE               2

// Packed Files - Fonts
const static char* FONT[] =
{
    "fonts/font_comic_16.xml",
    "fonts/font_comic_20.xml",
    "fonts/font_comic_24.xml"
};

// Packed Files - Icons
const static char* CHECKMARK[] =
{
    "icons/checkmark_24.png",
    "icons/checkmark_32.png",
    "icons/checkmark_48.png"
};

// Packed Files - Images
#define CHARACTER_UNARMED "images/character_unarmed.png"
#define DEVELOPER_IMAGE   "images/developer_screen.png"
#define GAME_IMAGE        "images/game_screen.png"
#define HIGHLIGHT_NONE    "images/highlight_none.png"
#define HIGHLIGHT_GREEN   "images/highlight_green.png"
#define MOUSEMAP_IMAGE    "images/mousemap.png"
#define MENU_IMAGE        "images/menu_screen.png"
#define OPPONENT_UNARMED  "images/opponent_unarmed.png"
#define TITLE_IMAGE       "images/title_screen.png"

// Packed Files - Meshes
#define DISPLAY_PLANE   "meshes/plane_1920x1200.3ds"
#define CHARACTER_PLANE "meshes/plane_256x256.3ds"
#define OVERLAY_PLANE   "meshes/plane_256x256.3ds"

// Position - Buttons
#define Y_BUTTON_START         240
#define Y_BUTTON_RESUME         80
#define Y_BUTTON_OPTIONS       -80
#define Y_BUTTON_EXIT         -240
#define Y_BUTTON_OPTIONS_DONE -320

// Position - Checkboxes
#define Y_CHECKBOX_MUSIC  0

// Position - UI Text
#define STAT_LABEL_X       -750
#define STAT_VALUE_X       -500
#define X_Y_CONTINUE                  0, -150
#define X_Y_BRAWN_LBL      STAT_LABEL_X,  520
#define X_Y_AGILITY_LBL    STAT_LABEL_X,  440
#define X_Y_BRAINS_LBL     STAT_LABEL_X,  360
#define X_Y_STAMINA_LBL    STAT_LABEL_X,  280
#define X_Y_HIT_POINTS_LBL STAT_LABEL_X,  200
#define X_Y_ACTION_LBL     STAT_LABEL_X,  120
#define X_Y_DEFENSE_LBL    STAT_LABEL_X,   40
#define X_Y_WEAPON_LBL     STAT_LABEL_X,  -40
#define X_Y_DAMAGE_LBL     STAT_LABEL_X, -120
#define X_Y_UNSPENT_LBL    STAT_LABEL_X, -200
#define X_Y_BRAWN          STAT_VALUE_X,  520
#define X_Y_AGILITY        STAT_VALUE_X,  440
#define X_Y_BRAINS         STAT_VALUE_X,  360
#define X_Y_STAMINA        STAT_VALUE_X,  280
#define X_Y_HIT_POINTS     STAT_VALUE_X,  200
#define X_Y_ACTION         STAT_VALUE_X,  120
#define X_Y_DEFENSE        STAT_VALUE_X,   40
#define X_Y_WEAPON         STAT_VALUE_X,  -40
#define X_Y_DAMAGE         STAT_VALUE_X, -120
#define X_Y_UNSPENT        STAT_VALUE_X, -200

// Root Nodes

// Strings
#define STRING_AGILITY    L"Agility:"
#define STRING_BRAINS     L"Brains:"
#define STRING_BRAWN      L"Brawn:"
#define STRING_CONTINUE   L"Click the screen or press the spacebar to continue"
#define STRING_DAMAGE     L"Damage:"
#define STRING_DEFENSE    L"Defense:"
#define STRING_HIT_POINTS L"Hit Points:"
#define STRING_ACTION     L"Action Points:"
#define STRING_STAMINA    L"Stamina:"
#define STRING_UNSPENT    L"Unspent Points:"
#define STRING_WEAPON     L"Weapon:"

// Z Values
#define CHARACTER_Z      824.0
#define DISPLAY_PLANE_Z CHARACTER_Z + 2.0
#define HEX_OVERLAY_Z   CHARACTER_Z + 1.0
#define MAX_Z           1100.0
#define TEXT_Z          CHARACTER_Z - 1.0
#define Z_OFFSET_1_250   199.0
#define Z_OFFSET_1_333   165.0
#define Z_OFFSET_1_600     0.0
#define Z_OFFSET_1_777     0.0

// Widget Size Modifiers
#define CHECKBOX_SIZE      32
#define MENU_BUTTON_HEIGHT  1.75
#define MENU_BUTTON_WIDTH   8
#define STAT_BUTTON_HEIGHT  1
#define STAT_BUTTON_WIDTH   2

// Sound
#define SND_DEVICE    -1
#define SND_FREQ   44100

// Weapons
const static char* WEAPON_NAME[] =
{
    "Hands",
    "Knife",
    "Club",    
    "Spear"
};
#define WEAPON_HANDS 0
#define WEAPON_KNIFE 1
#define WEAPON_CLUB  2
#define WEAPON_SPEAR 3

#endif /* CONSTANTS_H */
