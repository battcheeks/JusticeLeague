#ifndef Batman_H
#define Batman_H

// File: Batman.h
// Author: Nikhilesh
// Contents: This file contains the description of a class that represents
// Batman characters.

#include "Hero.h"

class Batman : public Hero
{
    public:
        Batman();
	Batman(bool isEnemyChar);
        string status();
        string attackText(string enemyName);
        void doAction (int actionNum, Character * target);
	void getMad ();
};

#endif
