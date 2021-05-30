#ifndef CHARACTER_H
#define CHARACTER_H

// File: Character.h
// Author: Aniruddha Kulkarni
// Contains: This file contains the description of a class called Character.

#include <iostream>
using namespace std;

class Character
{
    public:
        Character();
		Character(bool isEnemyChar);
		int numActions ();
		string action (int actionNum);
		int getCost (int actionNum);
		void setName (string newName);
		string getName();
		int getMaxHP ();
		int getMaxSP ();
		void setHP(int newHP);
		void damage(int damage);
		void heal(int hitPoints);
		int getHP();
		void spendSP(int cost);
		void gainSP(int skillPoints);
		int getSP();
		int getAtt();
		int getDef();
		int getEva();
		void kill();
		void revive();
		bool isAlive();
		bool isEnemy();
		virtual string status();
		virtual string attackText(string enemyName);
		virtual void onEvade(Character * target);
		virtual void doAction (int actionNum, Character * target);
		virtual void attack (Character * target);

		protected:
		string actions[4];
		int cost[4];
		string name;
		int maxHP;
		int maxSP;
		int HP;
		int SP;
		int att;
		int def;
		int eva;
		bool alive;
		bool enemyChar;
	
};

#endif
