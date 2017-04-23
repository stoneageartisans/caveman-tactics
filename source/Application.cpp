/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Application.h"
#include "Logger.h"

#include <fstream>

/******************
 * Public Methods *
 ******************/ 

// Constructor
Application::Application()
{
    initialize();
}

// Destructor
Application::~Application()
{
    dispose();
}

void Application::exit()
{
    irrlicht_device->setEventReceiver( 0 );
    irrlicht_device->closeDevice();
    irrlicht_device->run();
}

bool Application::OnEvent( const SEvent& EVENT )
{
    bool was_handled = false;
    
    switch( current_screen )
    {
        case GAME:
            switch( EVENT.EventType )
            {
                case EET_MOUSE_INPUT_EVENT:
                    switch( EVENT.MouseInput.Event )
                    {
                        case EMIE_LMOUSE_LEFT_UP:
                            mousemap_x = EVENT.MouseInput.X;
                            mousemap_y = EVENT.MouseInput.Y;
                            was_handled = true;
                            break;
                    }
                    break;
                case EET_KEY_INPUT_EVENT:
                    switch( EVENT.KeyInput.Key )
                    {
                        case KEY_ESCAPE:
                            if( !EVENT.KeyInput.PressedDown )
                            {
                                //hide_game_screen();
                                //show_main_menu();
                                was_handled = true;
                            }
                            break;
                    }
                    break;
            }
            break;
        case MENU:
            break;
        case CHARACTER:
            break;
        case TITLE:
            switch( EVENT.EventType )
            {
                case EET_MOUSE_INPUT_EVENT:
                    if( EVENT.MouseInput.Event == EMIE_LMOUSE_LEFT_UP )
                    {
                        //textnode_continue->setVisible( false );
                        //show_main_menu();
                        was_handled = true;
                    }
                    break;
                case EET_KEY_INPUT_EVENT:
                    if( EVENT.KeyInput.Key == KEY_SPACE )
                    {
                        if( !EVENT.KeyInput.PressedDown )
                        {
                            //textnode_continue->setVisible( false );
                            //show_main_menu();
                            was_handled = true;
                        }
                    }
                    break;
            }
            break;
        case OPTIONS:
            break;
        case NO_SCREEN:
            break;
    }
    
    return was_handled;
}

void Application::run()
{
    // TDOD
}

/*******************
 * Private Methods *
 *******************/

void Application::check_timer()
{
    if( timer_is_running )
    {
        if( ( irrlicht_device->getTimer()->getRealTime() - timer_start ) > timer_delay )
        {            
            execute_process( delayed_process );
            reset_timer();
        }
    }
}

void Application::dispose()
{
    delete color_background;
    delete color_white;
    delete rect_screen;
    delete ui;
    delete utilities;
}

void Application::execute_process( Process PROCESS )
{
    switch( PROCESS )
    {
        case NO_PROCESS:
            // Do nothing
            break;
        case SHOW_TITLE_SCREEN:
            show_title_screen();
            break;
        case SHOW_MAIN_MENU:
            show_main_menu();
            break;
    }
}

void Application::initialize()
{
    utilities = new Utilities();
        
    initialize_settings();
    initialize_irrlicht();
    initialize_values();
    initialize_display();
    initialize_camera();
    
    show_splash_screen();
    
    load_resources();
    
    ui = new UserInterface( irrlicht_device, z_offset );
}

void Application::initialize_camera()
{
    camera = scene_manager->addCameraSceneNode();
    camera->setFarValue( MAX_Z );
    camera->setPosition( vector3df( 0, 0, 0 ) );
    camera->setTarget( vector3df( 0, 0, 1 ) );
}

void Application::initialize_display()
{
    z_offset = 0.0;
    
    f32 screen_ratio = (f32) ( (f32) screen_width / (f32) screen_height );
    
    if( ( screen_ratio >= 1 ) && ( screen_ratio < 1.3 ) )
    {
        z_offset = Z_OFFSET_1_250;
    }
    else if( ( screen_ratio >= 1.3 ) && ( screen_ratio < 1.47 ) )
    {
        z_offset = Z_OFFSET_1_333;
    }
    else if( ( screen_ratio >= 1.47 ) && ( screen_ratio < 1.69 ) )
    {
        z_offset = Z_OFFSET_1_600;
    }
    else if( ( screen_ratio >= 1.69 ) && ( screen_ratio < 1.86 ) )
    {
        z_offset = Z_OFFSET_1_777;
    }
        
    rect_screen = new rect<s32>( vector2d<s32>(0, 0),
                                 vector2d<s32>( screen_width, screen_height ) );
    
    node_display_plane = scene_manager->addMeshSceneNode( scene_manager->getMesh( DISPLAY_PLANE ) );
    node_display_plane->setMaterialFlag( EMF_LIGHTING, false );
    node_display_plane->setPosition( vector3df( 0, 0, ( DISPLAY_PLANE_Z + z_offset ) ) );
    node_display_plane->setMaterialTexture( 0, video_driver->getTexture( DEVELOPER_IMAGE ) );
}

void Application::initialize_irrlicht()
{
    irrlicht_device = createDevice( driver_type,
                                    *screen_dimensions,
                                    BIT_DEPTH,
                                    display_type );    
    irrlicht_device->setResizable( false );
    irrlicht_device->setWindowCaption( WINDOW_CAPTION );
    irrlicht_device->getFileSystem()->addFileArchive( FILE_RESOURCES );
    irrlicht_device->setEventReceiver( this );
    
    video_driver = irrlicht_device->getVideoDriver();
    video_driver->setTextureCreationFlag( ETCF_CREATE_MIP_MAPS, false );
    
    scene_manager = irrlicht_device->getSceneManager();
    gui_environment = irrlicht_device->getGUIEnvironment();
}

void Application::initialize_settings()
{
    IrrlichtDevice* temp_device = createDevice( EDT_NULL );
    
    // Fallback values
    display_type = FULLSCREEN;
    driver_type = EDT_BURNINGSVIDEO;
    screen_width = temp_device->getVideoModeList()->getDesktopResolution().Width;
    screen_height = temp_device->getVideoModeList()->getDesktopResolution().Height;
    is_new_game = true;
    
    load_data( FILE_SETTINGS );
    
    stringc* value = NULL;
    
    if( data.find( "display_type" ) != 0 )
    {
        value = new stringc( data["display_type"] );
        if( value->equalsn( "windowed", 8 ) )
        {
            display_type = WINDOWED;
        }
        else if( value->equalsn( "fullscreen", 10 ) )
        {
            display_type = FULLSCREEN;
        }
    }
    if( data.find( "driver_type" ) != 0 )
    {
        value = new stringc( data["driver_type"] );
        if( value->equalsn( "opengl", 8 ) )
        {
            driver_type = EDT_OPENGL;
        }
        else if( value->equalsn( "software", 10 ) )
        {
            driver_type = EDT_BURNINGSVIDEO;
        }
    }
    if( data.find( "screen_width" ) != 0 )
    {
        value = new stringc( data["screen_width"] );
        screen_width = (s32) atoi( value->c_str() );
    }
    if( data.find( "screen_height" ) != 0 )
    {
        value = new stringc( data["screen_height"] );
        screen_height = (s32) atoi( value->c_str() );
    }
    if( data.find( "is_new_game" ) != 0 )
    {
        value = new stringc( data["is_new_game"] );
        if( value->equalsn( "true", 4 ) )
        {
            is_new_game = true;
        }
        else if( value->equalsn( "false", 5 ) )
        {
            is_new_game = false;
        }
    }
    
    delete value;
    
    screen_dimensions = new dimension2d<u32>( screen_width, screen_height );
    
    temp_device->drop();
}

void Application::initialize_values()
{
    color_background = new COLOR_DKGRAY;
    color_white = new COLOR_WHITE;
    timer_is_running = false;
    delayed_process = NO_PROCESS;
    current_screen = NO_SCREEN;
}

// Loads data from the specified file into data map
void Application::load_data( const char* FILENAME )
{
    char key[32];
    char value[32];
    
    std::ifstream input_file_stream( FILENAME );
    
    if( input_file_stream.is_open() )
    {
        while( input_file_stream >> key >> value )
        {
            data[key] = value;
        }
    }
    
    input_file_stream.close();
}

void Application::load_resources()
{
    texture_game_screen = video_driver->getTexture( GAME_IMAGE );
    texture_highlight_green = video_driver->getTexture( HIGHLIGHT_GREEN );
    texture_highlight_none = video_driver->getTexture( HIGHLIGHT_NONE );
    texture_menu_screen = video_driver->getTexture( MENU_IMAGE );
}

void Application::reset_timer()
{
    timer_is_running = false;
    delayed_process = NO_PROCESS;
    timer_delay = 0;
    timer_start = 0;
}

void Application::show_main_menu()
{
    // TODO
}

void Application::show_splash_screen()
{
    video_driver->beginScene( true, true, *color_background );
    scene_manager->drawAll();
    video_driver->endScene();
    
    start_timer( DELAY_SPLASH, SHOW_TITLE_SCREEN );
}

void Application::show_title_screen()
{
    node_display_plane->setMaterialTexture( 0, video_driver->getTexture( TITLE_IMAGE ) );
    
    video_driver->beginScene( true, true, *color_background );
    scene_manager->drawAll();
    gui_environment->drawAll();
    video_driver->endScene();
    
    current_screen = TITLE;
}

void Application::start_timer( u32 DELAY_DURATION, Process DELAYED_PROCESS )
{
    timer_is_running = true;
    delayed_process = DELAYED_PROCESS;
    timer_delay = DELAY_DURATION;    
    timer_start = irrlicht_device->getTimer()->getRealTime();
}