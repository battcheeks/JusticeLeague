//*******************************************************************
//
// Aniruddha Kulkarni - main.cpp -
//
// Justice League: A Data Structures based game
//
//*******************************************************************

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Random.h"
#include "Character.h"
#include "Batman.h"
#include "Superman.h"
#include "Green_Arrow.h"
#include "Flash.h"
#include "Martian.h"

using namespace std;

void displayBanner(string);
Character * pickCharacter(bool isEnemy);
void doOneTurn(Character * player, Character * enemy);
void displayMenu(Character * player, Character * enemy);
bool replay();

int main()
{
  Character * player;
  Character * enemy;
  bool play = true;
  char name[60];
  cout << "Enter your name: ";
  cin.getline(name, 60);
  while (play) {
    displayBanner(name);

    player = pickCharacter(false);
    enemy = pickCharacter(true);

    cout << "\tThe " << enemy->getName() << " stares you straight in the eyes. What ";
    cout << "do you do?" << endl << endl;
    
    while (player->isAlive() && enemy->isAlive())
      doOneTurn(player, enemy);

    displayMenu(player, enemy);

    play = replay();   
  }
    
  cout << endl << endl;
}

void displayBanner(string name)
{
  cout << endl;
  cout << "\t//////////////////////////////////////////////////////////////" << endl;
  cout << "\t                                                              " << endl;
  cout << "\t                  War Game: The Justice League                " << endl;
  cout << "\t                  Data Structures Course Project              " << endl;
  cout << "\t                  Welcome \033[31m" << name << "\033[0m                   " << endl;
  cout << "\t                                                              " << endl;
  cout << "\t//////////////////////////////////////////////////////////////" << endl << endl;
}

Character * pickCharacter(bool isEnemy)
{
  string who = (isEnemy) ? "enemy" : "your";
  cout << "\tChoose " << who << " character:\n\n";
  cout << "\t\t1. Batman";
  cout << "\t\t2. Superman\n";
  cout << "\t\t3. Green Arrow";
  cout << "\t\t4. Flash\n";
  cout << "\t\t5. Martian";
  cout << "\t\t6. Random\n\n\t> ";

  char choice;
  cin >> choice;
  cout << endl;

  while (!(choice - '0' > 0 && choice - '0' <= 6) && choice != 'q') {
    cout << "\tChoice invalid.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  if (choice == 'q') {
    Character * character = new Character;
    character->kill();
    return character;
  }

  int choiceNum = (choice == '6') ? random(5) : choice - '0';
  
  switch (choiceNum) {
    case 1:
      return  new Batman(isEnemy);

    case 2:
      return new Superman(isEnemy);

    case 3:
      return new Green_Arrow(isEnemy);

    case 4:
      return new Flash(isEnemy);

    case 5:
      return new Martian(isEnemy);

    default:
      return new Character(isEnemy);
  }
}

//*******************************************************************
//
// This function does one turn of the fight.
//
// pre: both players are alive
//
// post: one turn in the battle passes
//
//*******************************************************************

void doOneTurn(Character* player, Character* enemy)
{
  char choice;
  displayMenu(player, enemy);
  cout << "\t> ";
  cin >> choice;
  cout << endl;
  
  while (!(choice - '0' > 0 && choice - '0' <= player->numActions()) && choice != 'q') {
    cout << "\tChoice invalid.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  while (player->getCost(choice - '0' - 1) > player->getSP() && choice != 'q') {
    cout << "\tNot enough SP.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  if (choice == 'q') {
    player->kill();
    return;
  }
    
  player->doAction(choice - '0', enemy);

  if (enemy->isAlive()) {

    int enemyAction = random(100);

    if (enemyAction <= 33 && enemy->getCost(1) < enemy->getSP())
      enemy->doAction(2, player);
    else
      enemy->doAction(1, player);

    cout << endl;
  }
}

//*******************************************************************
//
// This function displays the player's menu.
//
// pre: player has positive health
//
// post: menu has been displayed
//
//*******************************************************************
    
void displayMenu(Character * player, Character * enemy)
{
  string enemyName = (enemy->isAlive()) ? enemy->getName() : enemy->getName() + " x_x";
  string playerName = (player->isAlive()) ? player->getName() : player->getName() + " x_x";

  // Print the enemy's healthbar
  cout << "\t\033[31m+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << enemyName << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right << enemy->getHP() << "/" 
       << setw(3) << left << enemy->getMaxHP() << " [";

  for (int i = 0; i < 25; i++) {
    if (enemy->getHP() > i * enemy->getMaxHP() / 25)
      cout << "|";
    else cout << " ";
  }
  cout << "] |\n";
  cout << "\t| SP " << setw(3) << right << player->getSP() << "/"
       << setw(3) << left << player->getMaxSP() << " [";
  for (int i = 0; i < 25; i++)
  {
    if (enemy->getSP() > i * enemy->getMaxSP() / 25)
      cout << "|";
    else
      cout << " ";
  }
  

  cout << "] |\n";
  cout << "\t|                                        |" << endl;
  cout << "\t| "
       << "Current player ATTACK level is: " << enemy->getAtt() << "     |" << endl;
  cout << "\t| "
       << "Current player DEFENCE level is: " << enemy->getDef() << "    |" << endl;
  cout << "\t|                                        |\n";
  

  cout << "\t+----------------------------------------+\n\n";

  // Print the player's menu
  cout << "\t\033[0m+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << playerName << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right <<  player->getHP() << "/"
       << setw(3) << left << player->getMaxHP() << " [";

  for (int i = 0; i < 25; i++) {
    if (player->getHP() > i * player->getMaxHP() / 25)
      cout << "|";
    else cout << " ";
  }

  cout << "] |\n";
  cout << "\t| SP " << setw(3) << right <<  player->getSP() << "/"
       << setw(3) << left << player->getMaxSP() << " [";

  for (int i = 0; i < 25; i++) {
    if (player->getSP() > i * player->getMaxSP() / 25)
      cout << "|";
    else cout << " ";
  }
  
  cout << "] |\n";
  cout << "\t|                                        |\n";

  cout << "\t| "
       << "Current player ATTACK level is: " << player->getAtt() << "     |" << endl;
  cout << "\t| "
       << "Current player DEFENCE level is: " << player->getDef() << "    |" << endl;
  cout << "\t|                                        |\n";

  for (int i = 0; i < 2; i++) {
    cout << "\t|     " << i + 1 << ". " << setw(24) << left << player->action(i);
    if (player->getCost(i) != 0)
      cout << setw(3) << right << player->getCost(i) << " SP  |\n";
    else
      cout << "        |\n";
  }
  cout << "\t|                                        |\n";
  cout << "\t+----------------------------------------+\n\n";
}
 
bool replay()
{
  char decision;
    
  cout << "\tWould you like to play again? (y or n)\n\n\t> ";
  cin >> decision;
    
  if (decision == 'y') {
    cout << endl << endl;
    return true;
  } else
    return false;
}