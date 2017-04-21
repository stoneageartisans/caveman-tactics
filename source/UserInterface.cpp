/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "UserInterface.h"

/* Public Methods */

// Constructor
UserInterface::UserInterface( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET )
{
    initialize( IRRLICHT_DEVICE, Z_OFFSET );
}

// Destructor
UserInterface::~UserInterface( )
{
    dispose();
}

/* Private Methods */

void UserInterface::dispose()
{
    // TODO
}

void UserInterface::initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET )
{
    z_offset = Z_OFFSET;
    
    gui_environment = IRRLICHT_DEVICE->getGUIEnvironment();
    scene_manager = IRRLICHT_DEVICE->getSceneManager();
}
