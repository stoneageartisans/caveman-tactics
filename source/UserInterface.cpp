/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "UserInterface.h"

/* Public Methods */

// Constructor
UserInterface::UserInterface( IrrlichtDevice* IRRLICHT_DEVICE )
{
    initialize( IRRLICHT_DEVICE );
}

// Destructor
UserInterface::~UserInterface( )
{
    dispose();
}

bool UserInterface::OnEvent( const SEvent& EVENT )
{
    bool result = false;
    
    return result;
}

/* Private Methods */

void UserInterface::dispose()
{
    // TODO
}

void UserInterface::initialize( IrrlichtDevice* IRRLICHT_DEVICE )
{
    // TODO
}
