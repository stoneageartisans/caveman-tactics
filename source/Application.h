/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Utilities.h"
#include "constants.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Application
{
    public:
        Application();
        ~Application();
        void exit();
        void run();
        
    private:
        map<stringc, stringc> data;
        bool                  display_type;
        E_DRIVER_TYPE         driver_type;
        dimension2d<u32>*     screen_dimensions;
        s32                   screen_height;
        s32                   screen_width;
        Utilities*            utilities;
        
        void create_settings();
        void dispose();
        void initialize();
        void load_data( char* FILENAME );
};

#endif /* APPLICATION_H */

