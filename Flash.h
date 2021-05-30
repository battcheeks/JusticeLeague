#ifndef Flash_H
#define Flash_H

// File: Flash.h
// Author: Sarthak
// Contents: This file contains the sescription of a class that represents
// Flash characters.

#include "Hero.h"

class Flash : public Hero
{
    public:
        Flash();
        Flash(bool isEnemyChar);
        string status();
        string attackText(string enemyName);
        void onEvade(Character * target);
        void doAction (int actionNum, Character * target);
        void sidestep ();
};

#endif
