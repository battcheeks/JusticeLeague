#ifndef Superman_H
#define Superman_H

// File: Superman.h
// Author: Aditya
// Contents: This file contains the sescription of a class that represents
// Superman characters.

#include "Hero.h"

class Superman : public Hero
{
    public:
        Superman();
	Superman(bool isEnemyChar);
        string status();
        string attackText(string enemyName);
        void doAction (int actionNum, Character * target);
	void wellPlacedBlow (Character * target);
};

#endif
