/*
 * Copyright (C) 2013-2017 William Mann
 * This file is part of the "Caveman Tactics" game
 */

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
    public:
        Logger();
        ~Logger();
        void log( char* MESSAGE );
        
    private:
        void dispose();
        void initialize();
};

#endif /* LOGGER_H */

