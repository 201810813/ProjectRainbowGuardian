#include <iostream>
#include "pch.h"
#include "MRedWolf.h"
#include "MGoldenLizard.h"
#include "Item.h"
#include "Player.h"
int main()
{
	string name = "";
	shared_ptr<Player> player = Player::getInstance();
	MGoldenLizard mgl;
	cout << player->GetCurrentHP() << endl;
	mgl.Attack(*player);
	cout << player->GetCurrentHP() << endl;
}
