#ifndef Martian_H
#define Martian_H

// File: Martian.h
// Author: Sanika
// Contents: This file contains the sescription of a class that represents
// Martian characters.

#include "Hero.h"

class Martian : public Hero
{
    public:
        Martian();
		Martian(bool isEnemyChar);
        string status();
        string attackText(string enemyName);
		void doAction (int actionNum, Character * target);
		void attack (Character * target);
		void fireball (Character * target);
};

#endif
