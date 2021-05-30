// File: Green_Arrow.cpp
// Author: Aniruddha Kulkarni
// Contents: This file contains the implementation of the Green_Arrow class

#include "Green_Arrow.h"

Green_Arrow::Green_Arrow ()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Dig In";
    cost[1] = 30;
    name = "Green_Arrow";
    maxHP = 130;
    maxSP = 70;
    HP = maxHP;
    SP = maxSP;
    att = 30;
    def = 70;
    eva = 5;
    alive = true;
    enemyChar = false;
}

Green_Arrow::Green_Arrow (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Dig In";
    cost[1] = 30;
    name = "Green_Arrow";
    maxHP = 130;
    maxSP = 70;
    HP = maxHP;
    SP = maxSP;
    att = 30;
    def = 70;
    eva = 5;
    alive = true;
    enemyChar = isEnemyChar;
}

string Green_Arrow::status ()
{
    if (HP <= 0) {
        return "\tHe finally collapses in a pile of crumpled steel.";
    } else if (HP < maxHP / 4)
        return "\tDark blood seeps out of the gaps in his armor.";
    else if (HP < maxHP / 2)
        return "\tHis once shiny armor is now visibly battered.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe raises his sheild a little more readily now.";
    else
        return "\tHe stands tall in shining armor.";
}

string Green_Arrow::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou bombard arrows on " + enemyName + ".";
    else 
        return "\tThe " + enemyName + " hits you with his special attack.";
}

void Green_Arrow::doAction (int actionNum, Character * target)
{
    spendSP(cost[actionNum - 1]);

    if (actionNum == 1) {
        attack(target);
        if (target->isEnemy())
	    cout << target->status() << endl;

    } else if (actionNum == 2)
        digIn();

    cout << endl;
}

void Green_Arrow::digIn ()
{
    def += 10;

    if (!isEnemy())
      cout << "\tYou dig your heels into the ground, nothing is getting through you.\n";
    else
      cout << "\tThe Green Arrow digs his heels into the ground and raises his shield.\n";
}
