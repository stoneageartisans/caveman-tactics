/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef SOUND_H
#define SOUND_H

#include "bass.h"

class Sound
{
    public:
        Sound();
        ~Sound();
        void playMusic( bool RESTART );
        void setVolume( float NEW_VOLUME );
        void stopMusic();

    private:
        bool initialized;
        HSTREAM stream_handle_music;
};

#endif /* SOUND_H */
