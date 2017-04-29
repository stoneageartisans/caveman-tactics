/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "constants.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class UserInterface
{
    public:
        UserInterface( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET );
        ~UserInterface();
        void flash_text();
        void set_view( Screen SCREEN );
        
    private:
        IGUIButton*      button_exit;
        IGUIButton*      button_options;
        IGUIButton*      button_resume;     
        IGUIButton*      button_start;
        ITextSceneNode*  flashing_text;
        IGUIFont*        font_main;
        IGUIEnvironment* gui_environment;
        ISceneManager*   scene_manager;
        s32              screen_height;
        s32              screen_width;
        IGUISkin*        skin;
        ITextSceneNode*  textnode_continue;
        bool             title_screen_shown;
        IVideoDriver*    video_driver;
        f32              z_offset;
        
        void dispose();
        void hide_main_menu();
        void initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET );
        void initialize_fonts();
        void initialize_main_menu( ISceneCollisionManager* COLLISION_MANAGER,
                                   u32 BUTTON_WIDTH,
                                   u32 BUTTON_HEIGHT );
        void initialize_skin();
        void initialize_title_screen();
        void initialize_widgets();
        void show_main_menu();
};

#endif /* USERINTERFACE_H */

