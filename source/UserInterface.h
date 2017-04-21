/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class UserInterface : public IEventReceiver
{
    public:
        UserInterface( IrrlichtDevice* IRRLICHT_DEVICE );
        ~UserInterface( );
        bool OnEvent( const SEvent& EVENT ) override;
        
    private:
        IGUIEnvironment* gui_environment;
        
        void dispose();
        void initialize( IrrlichtDevice* IRRLICHT_DEVICE );
};

#endif /* USERINTERFACE_H */

