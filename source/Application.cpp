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
    execute_callback();
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
    bool result = false;
    
    return result;
}

void Application::run()
{
    // TDOD
}

/*******************
 * Private Methods *
 *******************/

void Application::dispose()
{
    delete color_background;
    delete color_white;
    delete rect_screen;
    delete ui;
    delete utilities;
}

void Application::execute_callback()
{
    switch( callback )
    {
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
    Logger::log( "Initializing Application..." );
    
    utilities = new Utilities();
        
    initialize_settings();
    initialize_irrlicht();
    initialize_values();
    initialize_display();
    initialize_camera();
    
    show_splash_screen();
    
    ui = new UserInterface( irrlicht_device, z_offset );
    
    Logger::log( "...Application initialized." );
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
    node_display_plane->setMaterialTexture( 0, video_driver->getTexture( DEVELOPER_IMAGE ) );
    node_display_plane->setPosition( vector3df( 0, 0, ( DISPLAY_PLANE_Z + z_offset ) ) );
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
    
    delete value;
    
    // For testing
    //screen_width = 1120; screen_height = 896; // Ratio 1.250
    //screen_width = 1152; screen_height = 864; // Ratio 1.333
    //screen_width = 1280; screen_height = 800; // Ratio 1.600
    //screen_width = 1366; screen_height = 768;  // Ratio 1.777
    
    screen_dimensions = new dimension2d<u32>( screen_width, screen_height );
    
    temp_device->drop();
}

void Application::initialize_values()
{
    color_background = new COLOR_DKGRAY;
    color_white = new COLOR_WHITE;
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

void Application::show_main_menu()
{
    // TODO
}

void Application::show_splash_screen()
{
    video_driver->beginScene( true, true, COLOR_DEVGRAY );
    scene_manager->drawAll();
    video_driver->endScene();
    
    start_timer( DELAY_SPLASH, SHOW_TITLE_SCREEN );
}

void Application::show_title_screen()
{
    // TODO
}

void Application::start_timer( u32 DELAY_DURATION, Callback CALLBACK )
{
    timer_delay = DELAY_DURATION;
    callback = CALLBACK;    
    timer_start = irrlicht_device->getTimer()->getRealTime();    
    timer_running = true;
}