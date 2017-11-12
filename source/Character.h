/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Character
{
    public:
        Character();
        Character( s32 BRAWN,
                s32 AGILITY,
                s32 BRAINS,
                s32 STAMINA,
                s32 UNSPENT_POINTS,
                s32 WEAPON,
                s32 WOUNDS );
        ~Character(); 
        s32 get_agility();
        s32 get_brawn();        
        s32 get_brains();
        s32 get_stamina();
        s32 get_hit_points();
        f32 get_initiative();
        s32 get_defense();
        s32 get_action();
        s32 get_action_points();
        s32 get_wounds();
        s32 get_damage_min();
        s32 get_damage_max();
        s32 get_unspent_points();
        s32 get_weapon();
        u32 get_current_facing();
        u32 get_current_hex();
        u32 get_previous_hex();
        void calculate_stats();
        void reset_action_points();
        void set_agility( s32 AGILITY );
        void set_brains( s32 BRAINS );
        void set_brawn( s32 BRAWN );        
        void set_current_facing( u32 DIRECTION );
        void set_current_hex( u32 HEX );
        void set_previous_hex( u32 HEX );
        void set_stamina( s32 STAMINA );
        void set_unspent_points( s32 UNSPENT_POINTS );
        void set_weapon( s32 WEAPON );
        void set_wounds( s32 WOUNDS );

    private:
        void initialize( s32 BRAWN,
                         s32 AGILITY,
                         s32 BRAINS,
                         s32 STAMINA,
                         s32 UNSPENT_POINTS,
                         s32 WEAPON,
                         s32 WOUNDS );
        s32 agility;
        s32 brains;
        s32 brawn;
        s32 stamina;        
        s32 hit_points;
        s32 defense;
        f32 intiative;
        s32 action;
        s32 action_points;
        s32 damage_min;
        s32 damage_max;
        s32 unspent_points;
        s32 weapon;
        s32 wounds;
        u32 current_facing;
        u32 current_hex;
        u32 previous_hex;
};

#endif /* PLAYER_H */
