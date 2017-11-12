/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "constants.h"
#include "Logger.h"
#include "Sound.h"

#include <cstddef>

Sound::Sound()
{
    initialized = BASS_Init( SND_DEVICE, SND_FREQ, 0, 0, NULL );
    
    if( initialized )
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
    if( initialized )
    {
        BASS_Free();
    }
}

void Sound::playMusic()
{
    if( initialized )
    {
        BASS_ChannelPlay( stream_handle_music, TRUE );
    }
}

void Sound::stopMusic()
{
    BASS_ChannelStop( stream_handle_music );
}
