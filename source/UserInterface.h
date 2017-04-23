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
        
    private:
        ITextSceneNode*  flashing_text;
        IGUIFont*        font_main;
        IGUIEnvironment* gui_environment;
        ISceneManager*   scene_manager;
        s32              screen_height;
        s32              screen_width;
        IGUISkin*        skin;
        ITextSceneNode*  textnode_continue;
        //IVideoDriver*    video_driver;
        f32              z_offset;
        
        void dispose();        
        void initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET );
        void initialize_fonts();
        void initialize_skin();
        void initialize_widgets();
};

#endif /* USERINTERFACE_H */

