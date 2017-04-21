/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "constants.h"
#include "UserInterface.h"
#include "Utilities.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Application : public IEventReceiver
{
    public:
        Application();
        ~Application();
        bool OnEvent( const SEvent& EVENT ) override;
        void exit();
        void run();
        
    private:
        ICameraSceneNode*     camera;
        SColor*               color_background;
        SColor*               color_white;
        map<stringc, stringc> data;
        bool                  display_type;
        E_DRIVER_TYPE         driver_type;
        IGUIEnvironment*      gui_environment;
        IrrlichtDevice*       irrlicht_device;
        IMeshSceneNode*       node_display_plane;
        rect<s32>*            rect_screen;
        ISceneManager*        scene_manager;
        dimension2d<u32>*     screen_dimensions;
        s32                   screen_height;
        s32                   screen_width;
        UserInterface*        ui;
        Utilities*            utilities;
        IVideoDriver*         video_driver;
        f32                   z_offset;
        
        void dispose();
        void initialize();
        void initialize_camera();
        void initialize_display();
        void initialize_irrlicht();
        void initialize_settings();
        void initialize_values();
        void load_data( const char* FILENAME );
};

#endif /* APPLICATION_H */

