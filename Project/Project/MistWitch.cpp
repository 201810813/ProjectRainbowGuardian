#include "pch.h"
#include "MistWitch.h"

MistWitch::MistWitch()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (10 * playerLevel);
	RandomManager::GetInstance()->setRange(5, 7);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (3 * playerLevel);
	int		def = playerLevel * 2;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	WitchStat = { "안개마녀",Hp , Hp, damage, def, 1.4, 20, 30, 13, 20 };
	dropItems[HEALTH_POTION] = WitchStat.dropRate;
	dropItems[POWER_POTION] = WitchStat.dropRate;
	bDead = false;
	
}

MistWitch::~MistWitch() {}
void MistWitch::Begin()
{
	CreateAnimations();
	Monster::animator->Play("Idle", true);
}

void MistWitch::Tick()
{
	Monster::Tick();
	if (bDead == false && Monster::animator->isCurAnimEnd()) {
		Monster::animator->Play("Idle", true);
	}
}

void MistWitch::CreateAnimations()
{
	vector<string> VecAnim01;
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣨⣿⢟⡿⣳⣶⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⣿⡹⠞⢹⡷⣯⠛⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣄⠀⠀⠀⠀⠀⠀⠀⣤⣿⣻⡴⣯⡄⢦⠿⣵⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⢿⣼⢻⡷⣄⠀⣠⣤⡤⢿⡷⣏⠳⠤⣙⢂⡉⢆⡃⢏⡿⠿⠿⠷⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣽⣻⣾⣿⣼⣋⠙⢻⣦⣄⠠⡙⠤⠓⡌⢆⠋⣹⠍⠲⡌⠐⢀⡄⣰⡌⠁⠀⢀⣺⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠑⠿⢻⣷⣶⣻⢿⣶⡭⣘⠱⡘⠂⠀⠉⠂⠱⣌⠳⣮⣿⣿⡇⠀⠀⢸⣷⠻⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⢯⣿⣞⡷⣌⣳⢷⣞⡶⣳⣶⢣⠜⣿⡻⣟⡿⢣⣀⣴⡿⠹⠀⣿⣀⣠⠶⠶⢶⡶⠂⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣻⡾⣽⣿⣴⢛⡾⣾⡽⣯⡟⢧⣻⢧⣻⣿⣶⢆⡉⠘⢻⠁⠀⣻⠉⠁⣠⡔⠃⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢻⣷⠛⠛⢀⣿⢫⣤⢠⣟⣿⡽⣷⢯⣟⠙⠛⣿⣭⡗⣆⠘⣄⠚⢀⣤⡟⠃⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠀⢿⠃⠀⠀⢛⣟⡾⡽⠍⣻⣟⣾⣦⣾⣿⣷⡻⣼⣳⢮⠁⡿⣷⣤⣤⡄⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⢣⡄⠀⠀⠀⠀⠙⢦⡐⢨⣟⡾⠁⠀⣸⠿⣿⣽⣿⡿⣳⢽⡳⡍⠂⠀⠀⢠⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⢎⡱⢦⣦⣀⣀⣀⣹⣶⣻⡄⠀⣴⣋⣀⣿⢿⣣⣽⠳⠏⡑⠈⠀⣀⠾⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠱⣂⣈⠹⢋⠿⣹⢯⣷⡃⠄⣼⢻⣝⣮⠳⠧⢋⠑⢀⣀⡴⠶⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠲⠛⠞⣡⣬⣜⣧⡄⣠⣡⣠⣤⣥⣘⠷⠛⠎⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠉⠘⢣⣽⡁⠁⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");


	vector<string> VecAnim02;
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣶⣶⣶⣆⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⢿⣛⡮⣗⣯⢿⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣤⢻⡝⢀⡘⣯⡟⣤⣿⣷⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣟⡷⣤⣄⠀⠀⠀⢀⠀⣿⣟⡾⣏⠛⣇⠚⠱⡛⡝⢿⣿⣻⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⢀⣰⣿⣻⡽⣾⣳⢯⠷⡴⣾⡏⠛⠉⢿⠱⡨⢑⡌⠳⢦⠵⣌⠒⡍⠉⠉⢉⡻⠇⠀⠀⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠸⠿⠷⠿⠻⠟⢿⣻⣶⣤⣘⣿⣷⣈⢆⡃⢖⠡⠎⠁⢺⠁⠤⣓⢠⣘⣶⣾⡇⠀⠀⢰⣞⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢸⣷⣿⡾⣽⣟⣧⠜⣪⣥⣠⣀⣄⣠⡰⠱⣎⣿⣿⣿⡇⠀⢀⣼⢿⠈⣷⠀⠀⣀⣀⣀⣀⡀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣽⣻⢾⣻⠜⣧⣏⡷⣏⡿⣿⢥⣫⢟⣧⣯⢇⡘⠶⢻⣯⠌⠀⣾⠷⠚⠉⢈⡝⠋⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢻⣿⣞⣿⡟⠛⣿⡜⡋⠹⢯⣿⡽⣦⣟⡿⣼⣿⣿⡝⣦⠀⢸⠀⣠⠚⢀⣰⡞⠃⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠀⣤⡖⠋⠙⣷⣹⢿⣽⡛⣷⣻⣞⣀⢠⣿⣽⢧⡻⣄⢾⠀⣴⣟⠃⡀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣷⡄⠀⠀⠀⠀⠉⢦⡀⢀⠰⣯⣟⠎⠁⢺⣽⣿⢿⣿⣿⡿⣣⢿⡽⠊⠁⠙⠉⣛⠟⠃⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠓⢞⡱⢄⣀⡀⠀⠀⠙⢦⣘⣷⠋⠀⣀⠾⠉⣿⣿⢿⡹⣞⡽⢃⠒⠁⠀⣀⠾⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠱⢎⡙⠛⣶⢶⡶⣾⢿⣞⡇⠀⢾⡷⣶⢻⣝⣮⡗⢏⠐⠁⢀⣄⠶⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠰⠶⣠⣥⣜⠳⠛⠾⡅⢂⠚⠓⠋⠗⡈⢢⣍⣤⡰⠞⠉⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠛⠛⢿⡆⢾⠗⠛⠞⠛⠃⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	
	vector<vector<string>> AnimInfo;
	AnimInfo.push_back(VecAnim01);
	AnimInfo.push_back(VecAnim02);
	Monster::animator->CreateAnimation("Idle", AnimInfo, 2, 0.15f);

	vector<string> VecAnim03;
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣰⣶⣶⣶⣶⣄⣠⣀⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⡾⡞⠹⣻⣼⢳⡾⣱⣭⣥⣍⣠⠙⠞⠓⢦⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⣿⣧⡄⠀⠀⠀⠀⠀⣠⡿⣤⣗⣠⡖⣧⠯⣟⣾⡽⣯⣿⣤⠛⠛⠻⣾⢦⣥⠛⠛⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⣿⣷⣻⢟⣧⡄⠀⣤⡛⠔⡨⣙⠳⣿⣳⣶⣼⡷⣿⣿⣻⣿⣷⣄⠀⠀⠘⠳⣟⣦⠀⠛⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⢿⣯⢿⡾⣽⠟⢿⡑⢎⠐⣠⢓⠸⣍⢻⠟⠿⠿⣽⣿⣯⣿⣿⡇⠀⠀⠀⠘⣳⡟⣤⠀⠻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠐⢿⣯⡽⣞⣶⣀⡼⢌⠒⣭⠈⣇⡘⠂⠀⢄⡰⢍⡷⣿⣿⣽⢳⣄⡀⠀⠀⠈⣿⣎⠷⣆⠸⢇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠐⢿⣽⣳⢾⡽⣞⣳⢮⣅⡈⠲⣌⢱⡒⡬⡱⢎⡶⣩⢟⣯⣟⡾⣅⡀⠀⠀⠻⣎⡟⣧⠇⠘⣇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠘⢻⣽⣯⢿⣽⣯⣟⡾⣛⡶⣯⢷⣧⣵⡱⣊⢵⣳⢮⣟⣾⣽⣻⣤⣀⠀⠀⣿⡝⣮⡗⡀⠺⢅⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠙⢯⣿⣿⣿⡿⣷⣯⢟⡷⣯⢟⣾⣷⣧⡎⣼⣻⣽⡞⢠⣸⣟⣯⡿⣤⣿⡝⡶⡝⠀⠀⣻⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠘⠋⢀⡴⡿⠉⢨⡽⣷⢯⣏⣿⣻⣿⡴⡟⠋⠛⢋⠛⠙⣻⣿⣻⡽⣺⡽⣏⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⡋⠀⠀⠀⣀⣘⣹⣟⡾⣵⣫⠙⡷⣤⣞⣹⣟⠋⠛⡙⣉⠳⡽⢣⣟⣮⡀⠀⠀⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠉⠶⠶⣀⡌⠻⣏⡹⢿⣷⣯⢿⡴⣀⠛⢿⣿⣿⣿⣽⣭⠋⣀⠶⢍⢺⡷⢄⡀⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢦⡈⣵⠊⠉⠻⠟⣿⣷⣎⡄⠻⢿⣍⠻⣉⢶⣽⢣⡄⢸⡇⠈⠱⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠁⠀⠀⠀⠁⠘⠻⠛⢦⡉⢌⣵⣞⠛⠈⣿⡇⢰⡇⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠀⠈⠀⠀⠉⠻⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim03);
	Monster::animator->CreateAnimation("Attack", AnimInfo, 1, 0.25f);

	vector<string> VecAnim04;
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡏⢳⣄⠀⠀⣠⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡸⣄⣼⠇⠈⣷⡠⠞⣡⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⠇⠛⣿⣹⠀⠋⢡⣴⡟⠃⠀⣠⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⠀⠀⢫⣼⣀⠖⠳⠿⢦⣀⣰⣞⡷⣫⣟⣿⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠁⠀⡐⣿⢺⡵⣾⢧⣤⣤⣭⣘⣧⠓⢈⣿⣚⣬⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⠀⢀⢿⡱⣯⣾⣟⡾⣏⣻⣾⡻⠜⢫⠍⠚⡍⠻⣟⣿⣿⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠀⢸⡯⢽⡇⠀⠛⣿⡽⣤⡓⡡⢍⠢⠭⣴⢨⠱⡈⢀⣀⢨⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠫⣀⢼⡹⢯⡇⠀⠀⣰⡟⣿⣳⠇⢊⠑⠀⠘⠀⢣⡱⢶⣿⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⠘⣹⢻⡇⠀⣴⡻⣝⢶⣇⡠⣤⣿⣞⣻⢻⣄⣻⡟⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢃⡈⢷⣻⠅⠻⣵⣿⣿⣾⣿⣿⠚⠯⢿⣷⣞⡷⣽⡗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢥⡠⢟⣿⡀⠻⣽⣞⡷⢟⡯⢿⡼⣟⠮⣿⣽⣂⣘⣟⣻⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢎⡖⣻⢆⣌⣾⠟⠾⠀⢁⣿⠉⠀⣿⣽⣿⣿⣿⡷⣾⣹⣷⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠤⣈⠡⠶⣶⣤⡴⣞⠇⠀⣴⠃⠈⠻⠯⠁⠸⣿⣳⡏⠁⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠱⢶⣩⣾⣽⠗⢠⡖⠁⠀⠀⠀⠀⠀⠀⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⢢⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⠃⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim04);
	Monster::animator->CreateAnimation("GetAttack", AnimInfo, 1, 0.25f);

	vector<string> VecAnim05;
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⡾⣟⣿⡿⣿⢷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⢫⢷⣻⠞⡽⣯⢿⡻⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣟⣵⣎⣻⣅⢂⡸⣹⣯⣵⣾⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢆⡀⠀⠰⣿⣾⢿⡭⢓⠭⠣⢽⣻⢇⠏⣿⠻⢿⣿⣧⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡶⢁⡸⣇⠀⢸⣿⢽⣋⢒⢩⡘⡅⠂⡹⢎⠲⠌⠃⠼⣿⣿⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⠏⣉⣯⢷⡹⢷⡬⠓⢎⠳⡌⢦⡑⠀⠁⣐⠩⣜⣲⠌⠀⣼⣿⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢿⣻⣾⣿⣺⣇⢨⡗⣠⣆⢣⡽⠾⠅⠉⠳⣼⠧⣜⣿⣶⡄⢺⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢛⡿⣸⡿⡽⣾⣿⣿⣿⣽⣻⡅⣀⢴⣦⣾⣏⢾⣿⣿⠛⠁⠀⠀⣠⣾⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⢣⣴⣟⣳⣽⣻⢯⡟⢿⣳⣏⠙⠹⣿⣳⢿⣾⠿⡻⢤⢟⣧⣴⣾⢿⠿⣽⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣿⣾⣿⣷⣋⠉⢋⡌⣐⢫⣿⣏⣄⡐⣫⣿⣏⣁⣀⣀⡘⣉⡋⣽⣏⣦⡘⢣⣻⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠙⠋⠛⠛⠋⠛⠙⠋⠛⠉⠋⠛⠙⠋⠋⠋⠙⠋⠛⠙⠛⠙⠋⠛⠙⠛⠙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim05);
	Monster::animator->CreateAnimation("Die", AnimInfo, 1, 0.25f);
}



double MistWitch::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0, TEXT_COLOR_TYPE::RED));
	return GetDamage() * GetSkillDamage();
}

void MistWitch::Attack()
{
	Monster::animator->Play("Attack", false);
	//스킬 쓸확률
	int skillProbability = 10;
	RandomManager::GetInstance()->setRange(0, 100);
	double Trigger = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());

	//스킬을 쓰면
	if (Trigger < skillProbability) {
		double	damage = UseSkill() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "스킬 공격 히트!", true, 0, TEXT_COLOR_TYPE::RED));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(int(damage)) + "받았습니다!!!.", true, 0, TEXT_COLOR_TYPE::RED));
		}
		else {
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 스킬 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
		}
	}
	//스킬을 아니 쓰면
	else {
		double	damage = GetDamage() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "일반 공격 히트! ", true, 0, TEXT_COLOR_TYPE::RED));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(int(damage)) + "받았습니다!.", true, 0, TEXT_COLOR_TYPE::RED));
		}
		else { WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 일반 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY)); }
	}
}

void MistWitch::GetAttack()
{
	Monster::animator->Play("GetAttacj", false);
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void MistWitch::DropItem() {
	RandomManager::GetInstance()->setRange(0.f, 1.f);  // 0.0 ~ 1.0 사이의 랜덤 값
	double randomChance = RandomManager::GetInstance()->getRandom<double>();
	for (const auto& item : dropItems) {
		if (randomChance <= item.second) {  // 확률에 맞는 아이템 드롭
			Item* droppedItem = nullptr;

			switch (item.first) {
			case HEALTH_POTION:
				droppedItem = new HealthPotion();
				break;
			case POWER_POTION:
				droppedItem = new PowerPotion();
				break;
			default:
				break;
			}

			if (droppedItem) {
				Player::getInstance()->AddItemToInventory(droppedItem);  // 플레이어 인벤토리에 아이템 추가
				WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, droppedItem->GetName() + "이(가) 드롭되었습니다.", true, 0, TEXT_COLOR_TYPE::GREEN));
			}
			delete droppedItem;
		}
	}
}


bool MistWitch::is_Die()
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
const string MistWitch::GetName()
{
	return WitchStat.name;
}
const double MistWitch::GetCurrentHP()
{
	return WitchStat.currentHp;
}
const double MistWitch::GetMaxHP()
{
	return WitchStat.maxHp;
}
const double MistWitch::GetDropRate()
{
	return WitchStat.dropRate;
}

const bool MistWitch::GetbDead()
{
	return bDead;
}

const int MistWitch::GetCoin()
{
	return WitchStat.coin;
}
const int MistWitch::GetDefense()
{
	return WitchStat.defense;
}
const int MistWitch::GetExp()
{
	return WitchStat.exp;
}
const int MistWitch::GetEvasion()
{
	return WitchStat.evasion;
}

const double MistWitch::GetSkillDamage()
{
	return WitchStat.skillDamage;
}

const double MistWitch::GetDamage()
{
	return WitchStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void MistWitch::SetCurrentHP(double hp)
{
	WitchStat.currentHp = hp;
}
