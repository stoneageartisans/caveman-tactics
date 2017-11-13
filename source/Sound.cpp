/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "constants.h"
#include "Logger.h"
#include "Sound.h"

#include <cstddef>

/******************
 * Public Methods *
 ******************/

Sound::Sound()
{
    if( BASS_Init( SND_DEVICE, SND_FREQ, 0, 0, NULL ) )
    {
        Logger::log( "BASS was successfully initialized" );
        
        stream_handle_music = BASS_StreamCreateFile( FALSE, FILE_MUSIC, 0, 0, BASS_SAMPLE_LOOP );
    }
    else
    {
        Logger::log( "ERROR: BASS initialization failed" );
    }
}

Sound::~Sound()
{
    BASS_Free();
}

void Sound::playMusic( bool RESTART )
{
    if( RESTART )
    {
        BASS_ChannelPlay( stream_handle_music, TRUE );
    }
    else
    {
        BASS_ChannelPlay( stream_handle_music, FALSE );
    }
}

void Sound::setVolume( float NEW_VOLUME )
{
    DWORD volume = NEW_VOLUME * 10000;
    
    BASS_SetConfig( BASS_CONFIG_GVOL_STREAM, volume );
}

void Sound::stopMusic()
{
    BASS_ChannelStop( stream_handle_music );
}
