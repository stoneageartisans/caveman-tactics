/*
 * Copyright (C) 2013-2016 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "Character.h"
#include "constants.h"

#include <cmath>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Character::Character()
{
    initialize( 10, 10, 10, 10, 10, WEAPON_HANDS, 0 );
}

Character::Character( s32 BRAWN, s32 AGILITY, s32 BRAINS, s32 STAMINA, s32 UNSPENT_POINTS, s32 WEAPON, s32 WOUNDS )
{ 
    initialize( BRAWN, AGILITY, BRAINS, STAMINA, UNSPENT_POINTS, WEAPON, WOUNDS );
}

Character::~Character()
{
    // TODO
}

void Character::calculate_stats()
{
    hit_points = std::round( (float) ( brawn + stamina ) / 2.0 );
    
    if( ( (float) agility / 2.0 ) > ( (float) ( brawn + agility + brains + stamina ) / 8.0 ) )
    {
        defense = std::round( (float) agility / 2.0 );
    }
    else
    {
        defense = std::round( (float) ( brawn + agility + brains + stamina ) / 8.0 );
    }
    
    intiative = (f32) ( agility + brains + stamina ) / 6.0;
    
    action = std::round( (float) ( agility + brains + stamina ) / 6.0 );    
    action_points = action;
    
    if( brawn > 9 )
    {
        damage_min = std::round( (float) ( brawn - 7 ) / 3.0 );
    }
    else
    {
        damage_min = 0;
    }
    if( brawn > 7 )
    {
        damage_max = std::round( (float) ( brawn - 5 ) / 2.0 );
    }
    else
    {
        damage_max = 1;
        if( brawn < 6 )
        {
            damage_max = 0;
        }
    }
    
    switch( weapon )
    {
        case WEAPON_KNIFE:
            damage_min = damage_min + 1;
            damage_max = damage_max + 2;
            break;
        case WEAPON_CLUB:
            damage_min = damage_min + 2;
            damage_max = damage_max + 3;
            break;
        case WEAPON_SPEAR:
            damage_min = damage_min + 1;
            damage_max = damage_max + 4;
            break;        
    }
}

s32 Character::get_brawn()
{
    return brawn;
}

s32 Character::get_agility()
{
    return agility;
}

s32 Character::get_brains()
{
    return brains;
}

s32 Character::get_stamina()
{
    return stamina;
}

s32 Character::get_hit_points()
{
    return hit_points;
}

f32 Character::get_initiative()
{
    return intiative;
}

s32 Character::get_defense()
{
    return defense;
}

s32 Character::get_action()
{
    return action;
}

s32 Character::get_action_points()
{
    return action_points;
}

s32 Character::get_wounds()
{
    return wounds;
}

s32 Character::get_damage_min()
{
    return damage_min;
}

s32 Character::get_damage_max()
{
    return damage_max;
}

s32 Character::get_unspent_points()
{
    return unspent_points;
}

s32 Character::get_weapon()
{
    return weapon;
}

u32 Character::get_current_facing()
{
    return current_facing;
}

u32 Character::get_current_hex()
{
    return current_hex;
}

u32 Character::get_previous_hex()
{
    return previous_hex;
}

void Character::initialize( s32 BRAWN, s32 AGILITY, s32 BRAINS, s32 STAMINA, s32 UNSPENT_POINTS, s32 WEAPON, s32 WOUNDS )
{
    brawn = BRAWN;
    agility = AGILITY;
    brains = BRAINS;
    stamina = STAMINA;    
    unspent_points = UNSPENT_POINTS;
    weapon = WEAPON;
    wounds = WOUNDS;
    
    calculate_stats();
    
    current_facing = 0;
    current_hex = 0;
    previous_hex = 0;
}

void Character::reset_action_points()
{
    action_points = action;
}

void Character::set_agility( s32 AGILITY )
{
    agility = AGILITY;
}

void Character::set_brains( s32 BRAINS )
{
    brains = BRAINS;
}

void Character::set_brawn( s32 BRAWN )
{
    brawn = BRAWN;
}

void Character::set_current_facing( u32 DIRECTION )
{
    current_facing = DIRECTION;
}

void Character::set_current_hex( u32 HEX )
{
    set_previous_hex( current_hex );
    current_hex = HEX;
}

void Character::set_previous_hex(u32 HEX)
{
    previous_hex = HEX;
}

void Character::set_stamina( s32 STAMINA )
{
    stamina = STAMINA;
}

void Character::set_unspent_points( s32 UNSPENT_POINTS )
{
    unspent_points = UNSPENT_POINTS;
}

void Character::set_weapon( s32 WEAPON )
{
    weapon = WEAPON;
}

void Character::set_wounds( s32 WOUNDS )
{
    wounds = WOUNDS;
}