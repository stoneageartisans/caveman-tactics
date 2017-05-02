/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "constants.h"
#include "Character.h"
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
        Screen                current_screen;
        map<stringc, stringc> data;
        Process               delayed_process;
        bool                  display_type;
        E_DRIVER_TYPE         driver_type;
        IGUIEnvironment*      gui_environment;
        IrrlichtDevice*       irrlicht_device;
        bool                  is_new_game;
        ILightSceneNode*      light;
        s32                   mousemap_x;
        s32                   mousemap_y;
        IMeshSceneNode*       node_display_plane;
        Character*            player;
        rect<s32>*            rect_screen;
        ISceneManager*        scene_manager;
        dimension2d<u32>*     screen_dimensions;
        s32                   screen_height;
        s32                   screen_width;
        ITexture*             texture_game_screen;
        ITexture*             texture_highlight_green;
        ITexture*             texture_highlight_none;
        ITexture*             texture_menu_screen;
        u32                   timer_delay;
        bool                  timer_is_running;
        u32                   timer_start;
        UserInterface*        ui;
        Utilities*            utilities;
        IVideoDriver*         video_driver;
        f32                   z_offset;
        
        void check_timer();
        void dispose();
        void execute_process( Process PROCESS );
        void initialize();
        void initialize_camera();
        void initialize_display();
        void initialize_irrlicht();
        void initialize_player();
        void initialize_settings();
        void initialize_values();
        void load_data( const char* FILENAME );
        void load_resources();
        void reset_timer();
        void show_splash_screen();
        void show_title_screen();
        void start_timer( u32 DELAY, Process DELAYED_PROCESS );
};

#endif /* APPLICATION_H */

