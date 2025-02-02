#include "pch.h"
#include "IceHedgehog.h"
#include "SoundManager.h"
#include "RandomManager.h"

IceHedgehog::IceHedgehog()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (1 * playerLevel);
	RandomManager::GetInstance()->setRange(5, 7);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (1 * playerLevel);
	int		def = playerLevel * 1;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	HedgehogeStat = { "🦔고드름치🦔", Hp, Hp, damage, def, 1.4, 20, 30, 13, 20 };
	dropItems[HEALTH_POTION] = HedgehogeStat.dropRate;
	dropItems[POWER_POTION] = HedgehogeStat.dropRate;
	bDead = false;
	
}

IceHedgehog::~IceHedgehog() {}

void IceHedgehog::Begin()
{
	CreateAnimations();
	Monster::animator->Play("Idle", true);
}

void IceHedgehog::Tick()
{
	Monster::Tick();
	if (bDead == false && Monster::animator->isCurAnimEnd()) {
		Monster::animator->Play("Idle", true);
	}
}

void IceHedgehog::CreateAnimations() 
{
	vector<string> VecAnim01;
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠂⠙⣿⠆⠀⠀⠀⠀⠀⠀⣠⣾⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡆⠀⠀⠠⣿⠂⠄⣹⣿⠆⠀⠀⠀⠀⣾⡉⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢋⢿⡇⠀⣠⡶⠉⠌⡐⣣⡟⣷⡆⠀⢀⣶⠉⠄⢿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⠀⠀⣤⠛⠀⠀⢻⣧⣼⡿⠟⠀⠀⠀⣽⢞⣿⡇⢠⡔⠋⠀⣀⢯⣿⡃⢠⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⣀⠠⣿⣆⡀⠀⣸⣟⡿⣝⠨⠐⡀⠀⢾⣻⣼⣻⣧⡄⣀⢶⡹⣾⣿⡿⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡯⢱⣾⠿⣷⡽⣄⠂⡽⣾⡝⡶⢁⣌⡷⣞⢧⣿⣽⣧⣸⣮⣷⣻⠀⣉⠶⣿⣧⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⡇⠈⠹⣶⡙⣾⣭⢷⣜⢧⡟⡷⣎⡾⢽⡈⣳⢏⡙⠹⣟⣿⣿⣿⣳⢞⣻⣽⣛⣉⠙⡿⠉⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⡿⢧⢧⣄⠡⠰⣿⣗⢯⣟⡾⣝⣞⡷⣭⠛⣤⡝⠃⠀⢦⣹⢿⣿⣴⣿⣷⣯⣷⣞⣷⡟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣯⡖⣄⠀⠡⣿⠟⢺⣟⡟⠺⣟⣷⠿⡁⣄⣤⣛⣾⢻⡟⣿⣿⣿⢿⣛⣾⡽⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣽⢦⣡⣿⣷⣿⡾⢷⣾⠿⣁⢂⡼⣞⣧⣿⣭⡷⢿⣿⣿⣿⣿⣽⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢛⣿⣿⣿⣷⣿⠏⠋⠁⢸⣷⣾⣿⣿⣷⣿⡍⢻⣿⡧⢀⣿⣿⠉⣿⣿⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");


	vector<string> VecAnim02;
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⣿⡀⠌⣻⣅⡀⠀⠀⠀⠀⣀⠶⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⣿⡇⠀⠀⣈⠿⠄⡰⢸⣿⣃⠀⠀⠀⢀⡿⠡⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠛⠀⣿⡅⢠⣴⡿⠀⠐⠀⣟⡶⣻⡇⠀⠐⣿⠀⠁⢾⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣦⣄⡄⠀⣿⡀⠀⠀⢺⣿⣿⡟⠱⠀⠀⠀⢾⣝⠿⣧⡰⠛⠀⢀⡜⣼⣿⣥⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡟⢹⣾⣿⣷⣠⠀⡜⢷⣫⣟⡠⢃⡐⣠⡹⣾⣻⣽⣿⣖⣤⣿⣼⠛⠿⣏⣽⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠏⠀⠻⣿⣷⣏⡶⣄⢫⡷⢾⣱⠢⣼⣳⣏⣷⠏⠛⡹⣟⣿⢿⡉⢂⡴⣮⢿⣷⡶⣴⣦⣦⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣿⡭⣧⣄⠡⢐⣿⡿⣽⣞⣧⡻⣭⢷⣛⡷⣯⠟⠂⠉⡴⣱⢿⣿⣤⣿⣿⡾⣵⢯⣳⣤⣔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡾⣥⡄⠀⡈⣿⣷⣻⣞⡷⣽⣾⣽⠻⢡⢠⣄⣻⣞⢿⡻⣟⣿⣿⣟⡿⣽⣻⡟⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⣟⡶⣈⣿⣅⣹⣾⣍⣘⢯⣑⡀⣧⠿⣭⣷⣛⡾⢿⣿⡿⣽⣯⡿⣽⡇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢛⣿⣿⣿⣿⣿⣿⣿⡏⢹⣿⣶⣿⣿⣾⣿⡍⢻⣿⡗⠠⣿⣿⠙⣻⣿⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	
	vector<vector<string>> animInfo;
	animInfo.push_back(VecAnim01);
	animInfo.push_back(VecAnim02);
	Monster::animator->CreateAnimation("Idle", animInfo,2, 0.15f);

	vector<string> VecAnim03;
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠂⠙⣿⠆⠀⠀⠀⠀⠀⠀⣠⣾⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡆⠀⠀⠠⣿⠂⠄⣹⣿⠆⠀⠀⠀⠀⣾⡉⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢋⢿⡇⠀⣠⡶⠉⠌⡐⣣⡟⣷⡆⠀⣀⣶⠉⠄⢿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⠀⠀⣤⠛⠀⠀⢻⣧⣼⡿⠟⠀⠀⠀⣽⢞⣿⣷⣼⣟⠋⠀⣀⢯⣿⡃⢠⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⣠⣠⣀⣤⣠⣼⣿⣧⣄⣤⣿⣆⡀⠀⣸⣟⡿⣝⠨⠐⡀⠀⢾⣻⡞⠏⣸⣯⣤⣦⣽⣾⣿⡿⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⢀⣀⡰⠶⠞⣉⠩⢉⡍⣻⢽⣻⡿⠿⠿⢿⡿⣜⡆⠤⣹⢾⡝⡶⢁⣌⡷⣿⡇⠉⢀⢘⣿⢿⡿⣿⡁⢨⡵⣻⣧⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⢀⣰⣎⢋⣁⡄⣐⢠⢂⡷⠾⡭⢿⣿⣟⣦⣀⠀⡙⣽⣞⡷⣜⢯⡽⣳⢎⣾⣿⡋⢁⢀⢦⣞⣯⢷⣿⣿⢧⣻⣼⢻⡟⣉⠙⡿⠉⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠚⠛⠛⠛⠋⠻⣽⣾⣿⣯⢧⣔⣫⢟⣿⣿⣿⡳⢄⡻⣼⣻⡽⣮⢳⣏⡿⣾⠛⢡⣒⣾⢿⣝⣮⣿⡿⣯⢷⣳⣯⣷⣻⡟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⢀⣠⣀⣄⣤⣠⣄⣿⢿⡞⣧⣟⣾⣻⣿⣿⣿⣆⠓⢻⣽⡛⢫⣿⢾⣿⠃⣤⣞⢯⣟⣾⣿⣟⡿⣽⣻⢷⣻⡞⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠈⠹⢏⣉⣹⡻⢿⣹⢮⡽⢶⣻⣿⣷⣿⠿⣿⣿⣷⣯⡿⢷⡶⠿⠿⠿⣿⡾⣭⣿⣾⣿⠿⣯⣿⣿⣯⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠈⠋⠙⣿⣷⣿⣾⣿⣷⡏⢛⣿⣯⠀⠙⣻⣿⡏⠁⠈⠃⠀⠀⠀⣿⣿⡍⢻⣿⣇⠐⣿⣿⠉⣿⣿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	animInfo.clear();
	animInfo.push_back(VecAnim03);
	Monster::animator->CreateAnimation("Attack", animInfo, 1, 0.25f);

	vector<string> VecAnim04;
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⢋⢿⣆⡀⠀⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⣿⡀⠌⣻⣅⡀⠀⠀⠀⠀⣀⠶⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⣿⡇⠀⠀⣈⠿⠄⡰⢸⣿⣃⠀⠀⠀⢀⡿⠡⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠛⡀⢿⡅⢠⣴⡿⠀⠐⠀⣟⣶⣻⡇⠀⠐⣿⠀⠁⢾⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣦⡀⠀⠀⣿⣤⠻⢦⣽⣿⣿⡟⠱⢀⣤⣤⡛⣿⣿⢧⡰⠛⠀⢀⡜⣼⣿⣥⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⢦⣐⣿⠉⠐⡻⣿⣞⣳⢯⣘⠿⡈⠥⣑⣾⣿⣿⣿⣖⣤⢻⡼⠛⠿⣏⣽⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣣⢰⣿⡿⠀⡈⠄⣻⣿⣻⡯⠉⠐⣠⢳⣽⢿⣟⡿⣿⣿⢯⠳⣉⢀⠶⣜⣿⣷⣦⢶⣴⡦⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢻⣿⣿⡽⣏⣧⠀⠀⢻⣿⡽⠓⠀⠸⡽⣏⡾⣝⣾⡟⢫⠙⠎⡠⣟⣯⣻⣝⠾⣥⣦⣌⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⣿⡽⢾⣡⠄⣻⡿⢓⠠⣜⢿⣱⢟⣼⡿⣯⢽⡒⢨⣴⣳⣟⣶⣟⡾⣿⣿⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⣾⣿⣿⣯⡟⣆⣽⣗⠬⣷⣻⣞⣿⣿⣿⣝⣮⢷⣻⣾⣷⣯⣟⣾⡽⣿⡿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢛⣿⣿⠋⠙⣻⣽⣿⣿⣿⣏⠙⠉⠛⣻⣿⠏⢻⣿⡟⠹⣿⣿⠉⣿⣿⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	animInfo.clear();
	animInfo.push_back(VecAnim04);
	Monster::animator->CreateAnimation("GetAttack", animInfo, 1, 0.25f);

	vector<string> VecAnim05;
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⣠⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡰⢿⣿⡿⠟⠀⠀⠀⠀⢰⣶⣶⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⢘⣿⣿⣿⣿⠟⠋⠔⣬⢳⣼⣷⣤⣤⠛⠛⡛⠛⠣⢘⠫⢙⠻⢛⠛⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡼⠃⠹⠎⡈⠗⠨⣄⡀⣞⣿⢆⠓⠺⢟⣥⡉⠤⢁⠀⡁⠘⠻⣦⣀⡌⣿⣂⣿⡿⢆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⣿⣱⢺⣴⣠⢀⠀⠓⠬⢳⠎⡽⣺⢧⣇⣠⢊⣽⡀⢷⣎⣴⢣⡀⢡⠿⣼⢧⣻⣜⣳⣛⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢫⣷⣿⣷⣯⣶⣶⣾⣶⣾⣶⣷⣾⣿⣷⣿⣾⣷⠋⠙⢫⣿⣿⣶⣿⣾⣿⡉⢻⣶⣿⣾⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	animInfo.clear();
	animInfo.push_back(VecAnim05);
	Monster::animator->CreateAnimation("Die", animInfo, 1, 0.25f);
}


double IceHedgehog::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
	return GetDamage() * GetSkillDamage();
}

void IceHedgehog::Attack()
{
	Monster::animator->Play("Attack", false);
	//스킬 쓸확률
	int skillProbability = 10;
	RandomManager::GetInstance()->setRange(0, 100);
	double Trigger = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());

	//스킬을 쓰면
	if (Trigger < skillProbability) {
		SoundManager::GetInstance()->PlayMusic("ice_blast_projectile_spell_01", 1, 0.5, true);

		double	damage = UseSkill() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "스킬 공격 히트!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(int(damage)) + "받았습니다!!!.", true, 0, TEXT_COLOR_TYPE::RED));
		}
		else {
			SoundManager::GetInstance()->PlayMusic("Herb3", 1, 0.5, true);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 스킬 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
		}
	}
	//스킬을 아니 쓰면
	else {
		PlayAttackSound();

		double	damage = GetDamage() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "일반 공격 히트! ", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(int(damage)) + "받았습니다!.", true, 0, TEXT_COLOR_TYPE::RED));
		}
		else {
			SoundManager::GetInstance()->PlayMusic("Herb3", 1, 0.5, true);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 일반 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
		}
	}
}

void IceHedgehog::GetAttack()
{
	Monster::animator->Play("GetAttack", false);
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void IceHedgehog::DropItem() {
	for (const auto& item : dropItems) {
		RandomManager::GetInstance()->setRange(0, 100);  // 0.0 ~ 1.0 사이의 랜덤 값
		int randomChance = RandomManager::GetInstance()->getRandom<double>();
		if (randomChance <= item.second) {  // 확률에 맞는 아이템 드롭
			if (item.first == HEALTH_POTION) {
				WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션이 드랍되었습니다.", true, 0, TEXT_COLOR_TYPE::GREEN));
				Player::getInstance()->AddItemToInventory(HEALTH_POTION);
			}
			else if (item.first == POWER_POTION) {
				WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션이 드랍되었습니다.", true, 0, TEXT_COLOR_TYPE::GREEN));
				Player::getInstance()->AddItemToInventory(POWER_POTION);
			}
		}
	}
}

bool IceHedgehog::is_Die()
{
	if (GetCurrentHP() <= 0) {
		Monster::animator->Play("Die", false);
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신이" + GetName() + "를 쓰러트렸습니다!", true, 0, TEXT_COLOR_TYPE::BLUE));
		DropItem();
		bDead = true;
		return bDead;
	}
	return bDead;
}




//---------------------------------
//           Get함수
//---------------------------------
const string IceHedgehog::GetName()
{
	return HedgehogeStat.name;
}
const double IceHedgehog::GetCurrentHP()
{
	return HedgehogeStat.currentHp;
}
const double IceHedgehog::GetMaxHP()
{
	return HedgehogeStat.maxHp;
}
const double IceHedgehog::GetDropRate()
{
	return HedgehogeStat.dropRate;
}

const bool IceHedgehog::GetbDead()
{
	return bDead;
}

const int IceHedgehog::GetCoin()
{
	return HedgehogeStat.coin;
}
const int IceHedgehog::GetDefense()
{
	return HedgehogeStat.defense;
}
const int IceHedgehog::GetExp()
{
	return HedgehogeStat.exp;
}
const int IceHedgehog::GetEvasion()
{
	return HedgehogeStat.evasion;
}

const double IceHedgehog::GetSkillDamage()
{
	return HedgehogeStat.skillDamage;
}

const double IceHedgehog::GetDamage()
{
	return HedgehogeStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void IceHedgehog::SetCurrentHP(double hp)
{
	HedgehogeStat.currentHp = hp;
}

void IceHedgehog::PlayAttackSound()
{
	RandomManager::GetInstance()->setRange(1, 3);
	int rand = RandomManager::GetInstance()->getRandom<int>();

	switch (rand)
	{
	case 1:
		SoundManager::GetInstance()->PlayMusic("ice_spell_impact_shatter_01", 1, 0.3f, true);
		break;

	case 2:
		SoundManager::GetInstance()->PlayMusic("ice_spell_impact_shatter_02", 1, 0.3f, true);
		break;

	case 3:
		SoundManager::GetInstance()->PlayMusic("ice_spell_impact_shatter_03", 1, 0.3f, true);
		break;

	default:
		break;
	}
}