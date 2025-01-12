#include "pch.h"
#include <iostream>
#include "MRedWolf.h"
#include "MGoldenLizard.h"
#include "Item.h"

int main()
{
	HealthPostion postion;
	double damage = 5;
	string chat = "";
	MGoldenLizard MGL;
	while (MGL.getHP() > 0) {
		MGL.Hitted(damage);
		cout << MGL.getHP() << endl;
	}
	postion.UseItem(MGL);
	cout << MGL.getHP() << endl;
	return 0;
}