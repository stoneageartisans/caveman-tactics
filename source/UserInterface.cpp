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
            show_main_menu();
            break;
        case GAME:
            hide_main_menu();
            break;
        case CHARACTER:
            break;
        case OPTIONS:
            break;
        case TITLE:
            break;
        case NO_SCREEN:
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

void UserInterface::hide_main_menu()
{
    button_exit->setVisible( false );
    button_options->setVisible( false );
    button_resume->setVisible( false );
    button_start->setVisible( false );
}

void UserInterface::initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET )
{
    z_offset = Z_OFFSET;
    
    video_driver = IRRLICHT_DEVICE->getVideoDriver();
    gui_environment = IRRLICHT_DEVICE->getGUIEnvironment();
    scene_manager = IRRLICHT_DEVICE->getSceneManager();
    
    screen_width = video_driver->getScreenSize().Width;
    screen_height = video_driver->getScreenSize().Height;
    
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

void UserInterface::initialize_main_menu( ISceneCollisionManager* COLLISION_MANAGER,
                                          u32 BUTTON_WIDTH,
                                          u32 BUTTON_HEIGHT )
{
    position2d<s32> temp_position;
    
    temp_position = COLLISION_MANAGER->getScreenCoordinatesFrom3DPosition( vector3df( 0, 240, TEXT_Z + z_offset ) );
    button_start = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( BUTTON_WIDTH / 2 ),
                                                                           temp_position.Y - ( BUTTON_HEIGHT / 2 ) ),
                                                          dimension2d<u32>( BUTTON_WIDTH, BUTTON_HEIGHT ) ),
                                               0,
                                               BUTTON_START,
                                               L"New Game" );
    temp_position = COLLISION_MANAGER->getScreenCoordinatesFrom3DPosition( vector3df( 0, 80, TEXT_Z + z_offset ) );
    button_resume = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( BUTTON_WIDTH / 2 ),
                                                                            temp_position.Y - ( BUTTON_HEIGHT / 2 ) ),
                                                           dimension2d<u32>( BUTTON_WIDTH, BUTTON_HEIGHT ) ),
                                                0,
                                                BUTTON_RESUME,
	                                            L"Resume Game" );
    temp_position = COLLISION_MANAGER->getScreenCoordinatesFrom3DPosition( vector3df( 0, -80, TEXT_Z + z_offset ) );
    button_options = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( BUTTON_WIDTH / 2 ),
                                                                             temp_position.Y - ( BUTTON_HEIGHT / 2 ) ),
                                                            dimension2d<u32>( BUTTON_WIDTH, BUTTON_HEIGHT ) ),
	                                             0,
	                                             BUTTON_OPTIONS,
	                                             L"Game Options" );
    temp_position = COLLISION_MANAGER->getScreenCoordinatesFrom3DPosition( vector3df( 0, -240, TEXT_Z + z_offset ) );
    button_exit = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( BUTTON_WIDTH / 2 ),
                                                                          temp_position.Y - ( BUTTON_HEIGHT / 2 ) ),
                                                         dimension2d<u32>( BUTTON_WIDTH, BUTTON_HEIGHT ) ),
	                                          0,
	                                          BUTTON_EXIT,
	                                          L"Exit Game" );
    
    hide_main_menu();
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

void UserInterface::initialize_title_screen()
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
    
    title_screen_shown = false;
}

void UserInterface::initialize_widgets()
{
    ISceneCollisionManager* collision_manager = scene_manager->getSceneCollisionManager();
    
    u32 button_width = font_main->getDimension( L"X" ).Width * 10;
    u32 button_height = font_main->getDimension( L"X" ).Height * 1.75;
    
    initialize_title_screen();
    initialize_main_menu( collision_manager, button_width, button_height );
}

void UserInterface::show_main_menu()
{
    button_exit->setVisible( true );
    button_options->setVisible( true );
    button_resume->setVisible( true );
    button_start->setVisible( true );
    
    if( !title_screen_shown )
    {
        flashing_text = NULL;
        textnode_continue->setVisible( false );
        title_screen_shown = true;
    }
}