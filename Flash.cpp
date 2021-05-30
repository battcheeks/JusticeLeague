// File: Flash.cpp
// Author: Sarthak
// Contents: This file contains the implementation of the Flash class

#include "Flash.h"

Flash::Flash ()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Sidestep";
    cost[1] = 30;
    //actions[2] = "Debilitate";
    name = "Flash";
    maxHP = 70;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 30;
    eva = 15;
    alive = true;
    enemyChar = false;
}

Flash::Flash (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Sidestep";
    cost[1] = 30;
    //actions[2] = "Debilitate";
    name = "Flash";
    maxHP = 70;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 30;
    eva = 15;
    alive = true;
    enemyChar = isEnemyChar;
}

string Flash::status ()
{
    if (HP <= 0) {
        return "\tHe drops. Looks like he wont live to fight another day.";
    } else if (HP < maxHP / 4)
        return "\tHe's bloody and wondering why he let this go so far.";
    else if (HP < maxHP / 2)
        return "\tHe now moves frantically rather that gracefully.";
    else if (HP < 3 * maxHP / 4)
        return "\tHis confidence has now turned to determination.";
    else
        return "\tHe looks confident and light on his feet.";
}

string Flash::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou slash at the " + enemyName + " with your lightning strike.";
    else 
        return "\tThe " + enemyName + " slashes at you with his attack.";
}

void Flash::onEvade (Character * target)
{
    cout << "\n\tAttack of Opportunity!\n";
    attack(target);
}

void Flash::doAction (int actionNum, Character * target)
{
    spendSP(cost[actionNum - 1]);

    if (actionNum == 1) {
        attack(target);
        if (target->isEnemy())
	    cout << target->status() << endl;

    } else if (actionNum == 2)
        sidestep();

    cout << endl;
}

void Flash::sidestep ()
{
    eva += 5;

    if (!isEnemy())
      cout << "\tYou take a step to the side, away from your enemy's gaze.\n";
    else
      cout << "\tThe Flash takes a step to the side, why is he so hard to hit?\n";
}
