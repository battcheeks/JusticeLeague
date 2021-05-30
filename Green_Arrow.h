#ifndef Green_Arrow_H
#define Green_Arrow_H

// File: Green_Arrow.h
// Author: Aniruddha Kulkarni
// Contents: This file contains the sescription of a class that represents
// Green_Arrow characters.

#include "Hero.h"

class Green_Arrow : public Hero
{
    public:
        Green_Arrow();
        Green_Arrow(bool isEnemyChar);
        string status();
        string attackText(string enemyName);
        void doAction (int actionNum, Character * target);
        void digIn ();
};

#endif
