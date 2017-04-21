/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

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
        ~UserInterface( );        
        
    private:
        IGUIEnvironment* gui_environment;
        ISceneManager*   scene_manager;
        f32              z_offset;
        
        void dispose();
        void initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET );
};

#endif /* USERINTERFACE_H */

