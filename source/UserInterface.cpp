/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#include "UserInterface.h"
#include "Logger.h"

/******************
 * Public Methods *
 ******************/

// Constructors
UserInterface::UserInterface()
{
    Logger::log( "ERROR: An empty UserInterface was created. Disposing..." );
    dispose();
}

UserInterface::UserInterface( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET, Character* PLAYER )
{
    initialize( IRRLICHT_DEVICE, Z_OFFSET, PLAYER );
}

// Destructor
UserInterface::~UserInterface()
{
    dispose();
}

void UserInterface::flash_text()
{
    if( flashing_text->isVisible() )
    {
        flashing_text->setVisible( false );
    }
    else
    {
        flashing_text->setVisible( true );
    }
}

void UserInterface::set_view( Screen SCREEN )
{
    switch( SCREEN )
    {
        case MAIN_MENU:
            hide_character_screen();
            show_main_menu();
            break;
        case GAME:
            hide_main_menu();
            hide_character_screen();
            break;
        case CHARACTER:
            hide_main_menu();
            show_character_screen();
            break;
        case OPTIONS:
            break;
        case TITLE:
            break;
        case NO_SCREEN:
            break;
    }
}

/*******************
 * Private Methods *
 *******************/

void UserInterface::dispose()
{
    player = NULL;
    delete player;
}

void UserInterface::hide_character_screen()
{
    button_brawn_plus->setVisible( false );
    button_brawn_minus->setVisible( false );
    button_agility_plus->setVisible( false );
    button_agility_minus->setVisible( false );
    button_brains_plus->setVisible( false );
    button_brains_minus->setVisible( false );
    button_stamina_plus->setVisible( false );
    button_stamina_minus->setVisible( false );
    textnode_brawn->setVisible( false );
    textnode_agility->setVisible( false );
    textnode_brains->setVisible( false );
    textnode_stamina->setVisible( false );
    textnode_hit_points->setVisible( false );
    textnode_defense->setVisible( false );
    textnode_action->setVisible( false );
    textnode_damage->setVisible( false );
    textnode_weapon->setVisible( false );
    textnode_unspent->setVisible( false );
    textnode_brawn_lbl->setVisible( false );
    textnode_agility_lbl->setVisible( false );
    textnode_brains_lbl->setVisible( false );
    textnode_stamina_lbl->setVisible( false );
    textnode_hit_points_lbl->setVisible( false );
    textnode_defense_lbl->setVisible( false );
    textnode_action_lbl->setVisible( false );
    textnode_damage_lbl->setVisible( false );
    textnode_weapon_lbl->setVisible( false );
    textnode_unspent_lbl->setVisible( false );
}

void UserInterface::hide_main_menu()
{
    button_exit->setVisible( false );
    button_options->setVisible( false );
    button_resume->setVisible( false );
    button_start->setVisible( false );
}

void UserInterface::initialize( IrrlichtDevice* IRRLICHT_DEVICE, f32 Z_OFFSET, Character* PLAYER )
{
    player = PLAYER;    
    z_offset = Z_OFFSET;
    
    video_driver = IRRLICHT_DEVICE->getVideoDriver();
    gui_environment = IRRLICHT_DEVICE->getGUIEnvironment();
    scene_manager = IRRLICHT_DEVICE->getSceneManager();
    
    screen_width = video_driver->getScreenSize().Width;
    screen_height = video_driver->getScreenSize().Height;
    
    initialize_fonts();
    initialize_skin();
    initialize_widgets();
}

void UserInterface::initialize_character_display()
{
    ISceneCollisionManager& collision_manager = *(scene_manager->getSceneCollisionManager());
    
    u32 button_width = font_main->getDimension( L"X" ).Width * STAT_BUTTON_WIDTH;
    u32 button_height = font_main->getDimension( L"X" ).Height * STAT_BUTTON_HEIGHT;
    
    position2d<s32> temp_position;
    
    textnode_brawn_lbl = scene_manager->addTextSceneNode( font_main,
                                                          STRING_BRAWN,
                                                          COLOR_BROWN,
                                                          0,
                                                          vector3df( X_Y_BRAWN_LBL, TEXT_Z + z_offset ),
                                                          -1 );
    
    textnode_agility_lbl = scene_manager->addTextSceneNode( font_main,
                                                            STRING_AGILITY,
                                                            COLOR_BROWN,
                                                            0,
                                                            vector3df( X_Y_AGILITY_LBL, TEXT_Z + z_offset ),
                                                            -1 );
    
    textnode_brains_lbl = scene_manager->addTextSceneNode( font_main,
                                                           STRING_BRAINS,
                                                           COLOR_BROWN,
                                                           0,
                                                           vector3df( X_Y_BRAINS_LBL, TEXT_Z + z_offset ),
                                                           -1 );
    
    textnode_stamina_lbl = scene_manager->addTextSceneNode( font_main,
                                                            STRING_STAMINA,
                                                            COLOR_BROWN,
                                                            0,
                                                            vector3df( X_Y_STAMINA_LBL, TEXT_Z + z_offset ),
                                                            -1 );
    
    textnode_hit_points_lbl = scene_manager->addTextSceneNode( font_main,
                                                               STRING_HIT_POINTS,
                                                               COLOR_BROWN,
                                                               0,
                                                               vector3df( X_Y_HIT_POINTS_LBL, TEXT_Z + z_offset ),
                                                               -1 );
        
    textnode_action_lbl = scene_manager->addTextSceneNode( font_main,
                                                           STRING_ACTION,
                                                           COLOR_BROWN,
                                                           0,
                                                           vector3df( X_Y_ACTION_LBL, TEXT_Z + z_offset ),
                                                           -1 );
    
    textnode_defense_lbl = scene_manager->addTextSceneNode( font_main,
                                                            STRING_DEFENSE,
                                                            COLOR_BROWN,
                                                            0,
                                                            vector3df( X_Y_DEFENSE_LBL, TEXT_Z + z_offset ),
                                                            -1 );
    
    textnode_damage_lbl = scene_manager->addTextSceneNode( font_main,
                                                           STRING_DAMAGE,
                                                           COLOR_BROWN,
                                                           0,
                                                           vector3df( X_Y_DAMAGE_LBL, TEXT_Z + z_offset ),
                                                           -1 );
    
    textnode_weapon_lbl = scene_manager->addTextSceneNode( font_main,
                                                           STRING_WEAPON,
                                                           COLOR_BROWN,
                                                           0,
                                                           vector3df( X_Y_WEAPON_LBL, TEXT_Z + z_offset ),
                                                           -1 );
    
    textnode_unspent_lbl = scene_manager->addTextSceneNode( font_main,
                                                            STRING_UNSPENT,
                                                            COLOR_BROWN,
                                                            0,
                                                            vector3df( X_Y_UNSPENT_LBL, TEXT_Z + z_offset ),
                                                            -1 );
    
    textnode_brawn = scene_manager->addTextSceneNode( font_main,
                                                      stringw( player->get_brawn() ).c_str(),
                                                      COLOR_BLACK,
                                                      0,
                                                      vector3df( X_Y_BRAWN, TEXT_Z + z_offset ),
                                                      -1 );
    
    textnode_agility = scene_manager->addTextSceneNode( font_main,
                                                        stringw( player->get_agility() ).c_str(),
                                                        COLOR_BLACK,
                                                        0,
                                                        vector3df( X_Y_AGILITY, TEXT_Z + z_offset ),
                                                        -1 );
    
    textnode_brains = scene_manager->addTextSceneNode( font_main,
                                                       stringw( player->get_brains() ).c_str(),
                                                       COLOR_BLACK,
                                                       0,
                                                       vector3df( X_Y_BRAINS, TEXT_Z + z_offset ),
                                                       -1 );
    
    textnode_stamina = scene_manager->addTextSceneNode( font_main,
                                                        stringw( player->get_stamina() ).c_str(),
                                                        COLOR_BLACK,
                                                        0,
                                                        vector3df( X_Y_STAMINA, TEXT_Z + z_offset ),
                                                        -1 );
    
    stringw_hit_points = stringw( player->get_hit_points() - player->get_wounds() );
    stringw_hit_points += L" / ";
    stringw_hit_points += stringw( player->get_hit_points() ).c_str();
    textnode_hit_points = scene_manager->addTextSceneNode( font_main,
                                                           stringw_hit_points.c_str(),
                                                           COLOR_BLACK,
                                                           0,
                                                           vector3df( X_Y_HIT_POINTS, TEXT_Z + z_offset ),
                                                           -1 );
    
    stringw_action = stringw( player->get_action_points() );
    stringw_action += L" / ";
    stringw_action += stringw( player->get_action() ).c_str();
    textnode_action = scene_manager->addTextSceneNode( font_main,
                                                       stringw_action.c_str(),
                                                       COLOR_BLACK,
                                                       0,
                                                       vector3df( X_Y_ACTION, TEXT_Z + z_offset ),
                                                       -1 );
    
    textnode_defense = scene_manager->addTextSceneNode( font_main,
                                                        stringw( player->get_defense() ).c_str(),
                                                        COLOR_BLACK,
                                                        0,
                                                        vector3df( X_Y_DEFENSE, TEXT_Z + z_offset ),
                                                        -1 );
    
    textnode_weapon = scene_manager->addTextSceneNode( font_main,
                                                       stringw( WEAPON_NAME[player->get_weapon()] ).c_str(),
                                                       COLOR_BLACK,
                                                       0,
                                                       vector3df( X_Y_WEAPON, TEXT_Z + z_offset ),
                                                       -1 );
    
    stringw_damage = stringw( player->get_damage_min() );
    stringw_damage += L" - ";
    stringw_damage += stringw( player->get_damage_max() ).c_str();
    textnode_damage = scene_manager->addTextSceneNode( font_main,
                                                       stringw_damage.c_str(),
                                                       COLOR_BLACK,
                                                       0,
                                                       vector3df( X_Y_DAMAGE, TEXT_Z + z_offset ),
                                                       -1 );
    
    textnode_unspent = scene_manager->addTextSceneNode( font_main,
                                                        stringw( player->get_unspent_points() ).c_str(),
                                                        COLOR_BLACK,
                                                        0,
                                                        vector3df( X_Y_UNSPENT, TEXT_Z + z_offset ),
                                                        -1 );
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( textnode_brawn->getPosition() );
    temp_position.X += ( button_width * 1.1 );
    button_brawn_plus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                temp_position.Y - ( button_height / 2 ) ),
                                                               dimension2d<u32>( button_width, button_height ) ),
                                                    0,
                                                    BUTTON_BRAWN_PLUS,
                                                    L"+" );
    temp_position.X += ( button_width * 1.1 );
    button_brawn_minus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                 temp_position.Y - ( button_height / 2 ) ),
                                                                dimension2d<u32>( button_width, button_height ) ),
                                                     0,
                                                     BUTTON_BRAWN_MINUS,
                                                     L"-" );
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( textnode_agility->getPosition() );
    temp_position.X += ( button_width * 1.1 );
    button_agility_plus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                  temp_position.Y - ( button_height / 2 ) ),
                                                                 dimension2d<u32>( button_width, button_height ) ),
                                                      0,
                                                      BUTTON_AGILITY_PLUS,
                                                      L"+" );
    temp_position.X += ( button_width * 1.1 );
    button_agility_minus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                   temp_position.Y - ( button_height / 2 ) ),
                                                                  dimension2d<u32>( button_width, button_height ) ),
                                                       0,
                                                       BUTTON_AGILITY_MINUS,
                                                       L"-" );
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( textnode_brains->getPosition() );
    temp_position.X += ( button_width * 1.1 );
    button_brains_plus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                 temp_position.Y - ( button_height / 2 ) ),
                                                                dimension2d<u32>( button_width, button_height ) ),
                                                     0,
                                                     BUTTON_BRAINS_PLUS,
                                                     L"+" );
    temp_position.X += ( button_width * 1.1 );
    button_brains_minus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                  temp_position.Y - ( button_height / 2 ) ),
                                                                 dimension2d<u32>( button_width, button_height ) ),
                                                      0,
                                                      BUTTON_BRAINS_MINUS,
                                                      L"-" );
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( textnode_stamina->getPosition() );
    temp_position.X += ( button_width * 1.1 );
    button_stamina_plus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                  temp_position.Y - ( button_height / 2 ) ),
                                                                 dimension2d<u32>( button_width, button_height ) ),
                                                      0,
                                                      BUTTON_STAMINA_PLUS,
                                                      L"+" );
    temp_position.X += ( button_width * 1.1 );
    button_stamina_minus = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                                   temp_position.Y - ( button_height / 2 ) ),
                                                                  dimension2d<u32>( button_width, button_height ) ),
                                                       0,
                                                       BUTTON_STAMINA_MINUS,
                                                       L"-" );
    
    hide_character_screen();
}

void UserInterface::initialize_fonts()
{
    s32 screen_diagonal = squareroot( ( screen_width * screen_width ) + ( screen_height * screen_height ) );
    
    if( screen_diagonal < 1440 )
    {
        font_main = gui_environment->getFont( FONT_16 );
    }
    else if( screen_diagonal > 1920 )
    {
        font_main = gui_environment->getFont( FONT_24 );
    }
    else
    {
        font_main = gui_environment->getFont( FONT_20 );
    }
}

void UserInterface::initialize_main_menu()
{
    ISceneCollisionManager& collision_manager = *(scene_manager->getSceneCollisionManager());
    
    u32 button_width = font_main->getDimension( L"X" ).Width * MENU_BUTTON_WIDTH;
    u32 button_height = font_main->getDimension( L"X" ).Height * MENU_BUTTON_HEIGHT;
    
    position2d<s32> temp_position;
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( vector3df( 0, 240, TEXT_Z + z_offset ) );
    button_start = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                           temp_position.Y - ( button_height / 2 ) ),
                                                          dimension2d<u32>( button_width, button_height ) ),
                                               0,
                                               BUTTON_START,
                                               L"New Game" );
    
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( vector3df( 0, 80, TEXT_Z + z_offset ) );
    button_resume = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                            temp_position.Y - ( button_height / 2 ) ),
                                                           dimension2d<u32>( button_width, button_height ) ),
                                                0,
                                                BUTTON_RESUME,
	                                            L"Resume Game" );
    
    button_resume->setEnabled( false ); // temporary
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( vector3df( 0, -80, TEXT_Z + z_offset ) );
    button_options = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                             temp_position.Y - ( button_height / 2 ) ),
                                                            dimension2d<u32>( button_width, button_height ) ),
	                                             0,
	                                             BUTTON_OPTIONS,
	                                             L"Game Options" );
    
    button_options->setEnabled( false ); // temporary
    temp_position = collision_manager.getScreenCoordinatesFrom3DPosition( vector3df( 0, -240, TEXT_Z + z_offset ) );
    button_exit = gui_environment->addButton( rect<s32>( position2d<s32>( temp_position.X - ( button_width / 2 ),
                                                                          temp_position.Y - ( button_height / 2 ) ),
                                                         dimension2d<u32>( button_width, button_height ) ),
	                                          0,
	                                          BUTTON_EXIT,
	                                          L"Exit Game" );
    
    hide_main_menu();
}

void UserInterface::initialize_skin()
{
    skin = gui_environment->getSkin();
    
    skin->setFont( font_main );
    skin->setColor( EGDC_BUTTON_TEXT, COLOR_WHITE );
    skin->setColor( EGDC_GRAY_TEXT, COLOR_GRAY );
    skin->setColor( EGDC_WINDOW_SYMBOL, COLOR_WHITE );
    skin->setColor( EGDC_3D_FACE, COLOR_DKGRAY );       // Button base color
    skin->setColor( EGDC_3D_HIGH_LIGHT, COLOR_DKGRAY ); // Button border color
    skin->setColor( EGDC_3D_SHADOW, COLOR_DEVGRAY );    // Button shading color
}

void UserInterface::initialize_title_screen()
{    
    textnode_continue = scene_manager->addTextSceneNode( font_main,
                                                         STRING_CONTINUE,
                                                         COLOR_WHITE,
                                                         0,
                                                         vector3df( X_Y_CONTINUE,
                                                                    TEXT_Z + z_offset ),
                                                         -1 );
    textnode_continue->setVisible( false );
    
    flashing_text = textnode_continue;
    
    title_screen_shown = false;
}

void UserInterface::initialize_widgets()
{
    initialize_title_screen();
    initialize_main_menu();
    initialize_character_display();
}

void UserInterface::show_character_screen()
{
    textnode_brawn->setVisible( true );
    textnode_agility->setVisible( true );
    textnode_brains->setVisible( true );
    textnode_stamina->setVisible( true );
    textnode_hit_points->setVisible( true );
    textnode_defense->setVisible( true );
    textnode_weapon->setVisible( true );
    textnode_unspent->setVisible( true );
    textnode_action->setVisible( true );
    textnode_damage->setVisible( true );
    textnode_weapon->setVisible( true );
    textnode_unspent->setVisible( true );    
    textnode_brawn_lbl->setVisible( true );
    textnode_agility_lbl->setVisible( true );
    textnode_brains_lbl->setVisible( true );
    textnode_stamina_lbl->setVisible( true );
    textnode_hit_points_lbl->setVisible( true );
    textnode_defense_lbl->setVisible( true );
    textnode_action_lbl->setVisible( true );
    textnode_damage_lbl->setVisible( true );
    textnode_weapon_lbl->setVisible( true );
    textnode_unspent_lbl->setVisible( true );
    button_brawn_plus->setVisible( true );
    button_brawn_minus->setVisible( true );
    button_agility_plus->setVisible( true );
    button_agility_minus->setVisible( true );
    button_brains_plus->setVisible( true );
    button_brains_minus->setVisible( true );
    button_stamina_plus->setVisible( true );
    button_stamina_minus->setVisible( true );
}

void UserInterface::show_main_menu()
{
    button_exit->setVisible( true );
    button_options->setVisible( true );
    button_resume->setVisible( true );
    button_start->setVisible( true );
    
    if( !title_screen_shown )
    {
        flashing_text = NULL;
        textnode_continue->setVisible( false );
        title_screen_shown = true;
    }
}