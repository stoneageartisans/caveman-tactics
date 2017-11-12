/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "constants.h"
#include "Character.h"

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class UserInterface
{
    public:
        UserInterface();
        UserInterface( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET, Character* PLAYER );
        ~UserInterface();
        void flash_text();
        void set_view( Screen SCREEN );
        
    private:
        IGUIButton*      button_agility_minus;
        IGUIButton*      button_agility_plus;
        IGUIButton*      button_brains_minus;
        IGUIButton*      button_brains_plus;
        IGUIButton*      button_brawn_minus;
        IGUIButton*      button_brawn_plus;
        IGUIButton*      button_stamina_minus;
        IGUIButton*      button_stamina_plus;
        IGUIButton*      button_exit;
        IGUIButton*      button_options;
        IGUIButton*      button_resume;     
        IGUIButton*      button_start;
        Character*       player;
        ITextSceneNode*  flashing_text;
        IGUIFont*        font_main;
        IGUIEnvironment* gui_environment;
        ISceneManager*   scene_manager;
        s32              screen_height;
        s32              screen_width;
        IGUISkin*        skin;
        stringw          stringw_action;
        stringw          stringw_damage;
        stringw          stringw_hit_points;
        ITextSceneNode*  textnode_action;
        ITextSceneNode*  textnode_action_lbl;
        ITextSceneNode*  textnode_agility;
        ITextSceneNode*  textnode_agility_lbl;
        ITextSceneNode*  textnode_brains;
        ITextSceneNode*  textnode_brains_lbl;
        ITextSceneNode*  textnode_brawn;
        ITextSceneNode*  textnode_brawn_lbl;
        ITextSceneNode*  textnode_continue;
        ITextSceneNode*  textnode_stamina;
        ITextSceneNode*  textnode_stamina_lbl;        
        ITextSceneNode*  textnode_hit_points;
        ITextSceneNode*  textnode_hit_points_lbl;        
        ITextSceneNode*  textnode_defense;
        ITextSceneNode*  textnode_defense_lbl;
        ITextSceneNode*  textnode_weapon;
        ITextSceneNode*  textnode_weapon_lbl;
        ITextSceneNode*  textnode_damage;
        ITextSceneNode*  textnode_damage_lbl;        
        ITextSceneNode*  textnode_unspent;
        ITextSceneNode*  textnode_unspent_lbl;
        bool             title_screen_shown;
        IVideoDriver*    video_driver;
        f32              z_offset;
        
        void dispose();
        void hide_character_screen();
        void hide_main_menu();
        void initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET, Character* PLAYER );
        void initialize_character_display( );
        void initialize_fonts();
        void initialize_main_menu();
        void initialize_skin();
        void initialize_title_screen();
        void initialize_widgets();
        void show_character_screen();
        void show_main_menu();
};

#endif /* USERINTERFACE_H */
