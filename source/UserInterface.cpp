/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "UserInterface.h"

/******************
 * Public Methods *
 ******************/

// Constructor
UserInterface::UserInterface( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET )
{
    initialize( IRRLICHT_DEVICE, Z_OFFSET );
}

// Destructor
UserInterface::~UserInterface()
{
    dispose();
}

void UserInterface::flash_text()
{
    if( flashing_text->isVisible() )
    {
        flashing_text->setVisible( false );
    }
    else
    {
        flashing_text->setVisible( true );
    }
}

void UserInterface::set_view( Screen SCREEN )
{
    switch( SCREEN )
    {
        case MAIN_MENU:
            flashing_text = NULL;
            textnode_continue->setVisible( false );
            break;
        case GAME:
            break;
    }
}

/*******************
 * Private Methods *
 *******************/

void UserInterface::dispose()
{
    // TODO
}

void UserInterface::initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET )
{
    z_offset = Z_OFFSET;
    
    //video_driver = IRRLICHT_DEVICE->getVideoDriver();
    gui_environment = IRRLICHT_DEVICE->getGUIEnvironment();
    scene_manager = IRRLICHT_DEVICE->getSceneManager();
    
    screen_width = IRRLICHT_DEVICE->getVideoModeList()->getDesktopResolution().Width;
    screen_height = IRRLICHT_DEVICE->getVideoModeList()->getDesktopResolution().Height;
    
    initialize_fonts();
    initialize_skin();
    initialize_widgets();
}

void UserInterface::initialize_fonts()
{
    s32 screen_diagonal = squareroot( ( screen_width * screen_width ) + ( screen_height * screen_height ) );
    
    if( screen_diagonal < 1440 )
    {
        font_main = gui_environment->getFont( FONT_16 );
    }
    else if( screen_diagonal > 1920 )
    {
        font_main = gui_environment->getFont( FONT_24 );
    }
    else
    {
        font_main = gui_environment->getFont( FONT_20 );
    }
}

void UserInterface::initialize_skin()
{
    skin = gui_environment->getSkin();
    
    skin->setFont( font_main );
    skin->setColor( EGDC_BUTTON_TEXT, COLOR_WHITE );
    skin->setColor( EGDC_WINDOW_SYMBOL, COLOR_WHITE );
    skin->setColor( EGDC_3D_FACE, COLOR_GRAY );
    skin->setColor( EGDC_3D_HIGH_LIGHT, COLOR_DKGRAY );
}

void UserInterface::initialize_widgets()
{
    textnode_continue = scene_manager->addTextSceneNode( font_main,
                                                         STRING_CONTINUE,
                                                         COLOR_WHITE,
                                                         0,
                                                         vector3df( X_Y_CONTINUE,
                                                                    TEXT_Z + z_offset ),
                                                         -1 );
    textnode_continue->setVisible( false );
    
    flashing_text = textnode_continue;
}
