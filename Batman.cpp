// File: Batman.cpp
// Author: Nikhilesh
// Contents: This file contains the implementation of the Batman class

#include "Batman.h"

Batman::Batman()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Get Mad";
    cost[1] = 30;
    name = "Batman";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = false;
}

Batman::Batman(bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Get Mad";
    cost[1] = 30;
    //actions[2] = "Charge";
    name = "Batman";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = isEnemyChar;
}

string Batman::status()
{
    if (HP <= 0)
    {
        return "\tHe's on the ground, out of blood, but he still has that crazy look in his eyes.";
    }
    else if (HP < maxHP / 4)
        return "\tHe's missing significant portions of his body, but still fights like a madman.";
    else if (HP < maxHP / 2)
        return "\tHis eyes no longer point the same direction, but he just keeps coming.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe has a few cuts, but nothing is slowing him down.";
    else
        return "\tMuscles flexing, he lets out a battle cry.";
}

string Batman::attackText(string enemyName)
{
    if (!isEnemy())
        return "\tYou swing your batarang at the " + enemyName + ".";
    else
        return "\tThe " + enemyName + " hits you with his super-power.";
}

void Batman::doAction(int actionNum, Character *target)
{
    spendSP(cost[actionNum - 1]);

    if (actionNum == 1)
    {
        attack(target);
        if (target->isEnemy())
            cout << target->status() << endl;
    }
    else if (actionNum == 2)
        getMad();

    cout << endl;
}

void Batman::getMad()
{
    att += 10;
    def -= 5;

    if (!isEnemy())
        cout << "\tYou start to get mad, your only goal is to kill.\n";
    else
        cout << "\tThe Batman is getting angry. His attacks are more severe, but he looks more open.\n";
}
