#include "pch.h"
#include <iostream>
#include "MRedWolf.h"
#include "MGoldenLizard.h"


int main()
{
	int damage;
	string chat = "";
	MGoldenLizard MGL;
	do {
		cin >> damage;
		MGL.Hitted(damage);
		cout << MGL.getHP() - damage;
	} while (chat != "end");

	return 0;
}