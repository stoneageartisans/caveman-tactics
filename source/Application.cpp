/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Application.h"

#include <fstream>

/* Public Methods */

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
    // TODO
}

void Application::run()
{
    // TDOD
}

/* Private Methods */

void Application::create_settings()
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

void Application::dispose()
{
    delete utilities;
}

void Application::initialize()
{
    utilities = new Utilities();
    
    create_settings();
}

// Loads data from the specified file into data map
void Application::load_data( char* FILENAME )
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