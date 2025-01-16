#include "pch.h"
#include "PoisonSlime.h"


PoisonSlime::PoisonSlime()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>() + (1 * playerLevel));
	RandomManager::GetInstance()->setRange(5, 6);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>() + (1 * playerLevel));
	int		def = playerLevel * 1;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	SlimeStat = { "☠️독덩쿨이☠️", Hp, Hp, damage, def, 1.4, 20, 30, 22, 23 };
	dropItems[HEALTH_POTION] = SlimeStat.dropRate;
	dropItems[POWER_POTION] = SlimeStat.dropRate;
	bDead = false;
	
}

PoisonSlime::~PoisonSlime() {}

void PoisonSlime::Begin()
{
	CreateAnimations();
	Monster::animator->Play("Idle", true);
}

void PoisonSlime::Tick()
{
	Monster::Tick();
	if (bDead == false && Monster::animator->isCurAnimEnd()) {
		Monster::animator->Play("Idle", true);
	}
}

void PoisonSlime::CreateAnimations()
{
	vector<string> VecAnim01;
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⢛⡹⠳⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣠⢛⡻⠃⢀⣀⣀⣀⡿⢡⣹⡆⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⡄⠀⣮⡑⢺⠓⡞⢊⠡⣉⠩⢔⢣⡗⠀⣤⢾⡃⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣟⢷⡀⠟⢮⣣⠱⣄⡣⣞⣶⢣⠞⣋⣤⣰⢞⣿⡄⡾⢉⡶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢉⣯⠷⣼⠋⡁⠛⣡⢛⡼⢣⠏⡚⢤⡻⣝⣮⢿⣦⠛⣤⠿⢃⣴⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡜⣇⠀⢀⡼⢟⡁⠀⢀⡷⢮⣝⡞⣧⣛⡴⣫⢽⡽⠊⠘⣀⠣⡙⣳⢯⡟⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢣⣙⢶⡋⢴⡨⢔⡶⣫⢾⡁⢾⡝⢶⣣⡝⣶⢋⠆⣀⡰⣌⠳⠴⣡⠉⠶⡄⢀⣰⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡿⣎⡽⢳⡰⣎⡵⣏⢯⠻⡝⣜⣣⢷⡙⠌⣶⢢⣽⢳⡌⣇⡛⡤⢋⠰⢸⣟⣧⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣟⣿⡽⣞⡌⠳⢧⣻⡜⣄⣫⢟⣹⠮⠝⢢⠘⢤⢳⣓⢾⡻⠼⣜⠿⡐⣡⢊⠟⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠘⠻⣄⣲⣈⠃⠏⡽⢎⡳⢭⠐⡌⡘⠤⡹⢎⠷⠭⢶⡙⢯⠜⡀⠐⣠⣌⡲⠝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠑⠻⠞⠖⠳⠞⠖⠻⠒⠟⠶⠳⠞⠚⠷⠒⠛⠶⠛⠞⠳⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");


	vector<string> VecAnim02;
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⠶⠲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⣤⠤⠀⠀⠀⠘⣷⢈⠷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣤⠀⠀⡴⢋⡴⣯⣤⠴⠚⠖⡳⣉⠞⣼⠃⢀⣴⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⣧⠀⣿⡥⡚⠤⣀⢆⣩⣦⡑⣬⠞⠁⢀⡿⣾⡁⣤⠶⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣜⣧⣠⠾⡙⠶⠭⢎⡷⣍⡳⢎⡙⢿⢯⡳⣿⣄⠷⢠⣻⡄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡄⠀⠀⣻⠶⠏⠂⠀⣼⣡⢟⡴⣋⡵⣆⣼⢻⢾⡝⠚⢏⠘⣻⣤⡼⣟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⢯⣄⡞⣡⢋⣄⣠⢞⣵⠛⣺⡳⣝⢶⡹⣆⡟⡣⠀⢈⠴⣊⠔⡒⠻⣅⠀⠀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⣚⠶⣩⠒⡬⢳⡞⣞⣳⡜⡳⣜⢧⡛⠜⣳⠔⣮⡓⣎⠥⣋⠵⡡⢌⢳⡶⢯⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⣴⣾⣻⢼⠩⢷⣉⡟⣧⡙⣸⢵⡺⣵⢫⠎⠱⡈⣗⣫⢾⡽⣆⣻⣼⠒⡁⠴⣺⣽⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢳⢯⣋⢇⠨⠹⡽⢶⡹⢎⠷⠙⠄⠣⠌⡱⡜⢮⠵⢫⠼⡱⢞⠠⠁⡉⢒⣡⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠚⠳⠳⠞⠖⠳⠞⠶⠛⠞⠶⠓⠳⠞⠖⠻⠲⠛⠳⠛⠖⠳⠞⠓⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	
	vector<vector<string >> AnimInfo;
	AnimInfo.push_back(VecAnim01);
	AnimInfo.push_back(VecAnim02);
	Monster::animator->CreateAnimation("Idle", AnimInfo,2,0.15f);

	vector<string> VecAnim03;
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⢀⡖⢩⣩⡝⠃⠀⠀⠀⢀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⢺⣷⡄⠐⡏⣌⡡⠾⠖⠶⠶⢄⣀⠈⣱⠜⡳⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠙⢷⣻⢴⡻⣤⢣⣜⣠⢃⠰⣈⢅⡛⢻⣡⢓⡿⣄⣀⣀⣀⣤⣤⣤⣤⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⢠⣤⢚⣏⣷⠳⣿⡦⢛⠷⡎⢓⡹⢎⣩⠳⢬⡓⡴⢬⡹⣭⢻⣼⠶⡝⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⣴⢣⣾⡿⠻⠉⠙⠀⠁⣌⠲⣜⢮⡝⢋⠖⣃⠾⣱⢫⢧⡙⠎⢣⠟⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⢾⣉⠣⣐⠀⣀⣤⢲⡝⣎⠛⡌⣦⣘⣴⡞⢡⠋⠗⡫⢎⠉⠈⢀⢻⣦⡛⢛⢫⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⢸⣃⠙⣢⠼⣧⡜⣧⢋⠞⠨⡑⠤⣟⠀⠀⠘⢣⠾⢆⣑⣂⣲⠴⠮⠃⠙⠽⠏⠓⠀⢀⡴⢛⠲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠘⢧⡘⢼⡹⢶⡹⣆⠣⢌⡱⢈⡶⡘⢧⡀⠀⠀⡴⠻⢯⣭⠝⠶⠶⣤⡀⠀⠀⠀⠀⠚⡼⡉⣔⠠⣙⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⣀⣰⡶⣿⢾⡽⣧⢿⣹⢳⡌⡐⢣⠘⡹⣆⡹⢳⠟⣀⢤⣒⣦⢊⠔⡠⢀⠙⢦⡀⠀⠀⠀⠀⠳⣭⢳⢌⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠾⠿⠿⠿⠿⠋⠓⠶⣌⣃⠯⣚⣥⠳⣌⠰⢄⠛⡳⣞⡼⣧⣛⡎⢍⠪⣕⣎⡐⢎⣽⣦⣴⣞⡻⠏⠙⠶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⣦⢬⠷⣌⣓⣎⣱⣠⡙⠜⣱⢳⢺⡤⡓⣌⠰⣙⡚⢮⠓⢻⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠱⠛⠶⠚⠗⠛⠛⠞⠛⠳⠛⠶⠛⠶⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	
	AnimInfo.clear();
	AnimInfo.push_back(VecAnim03);
	Monster::animator->CreateAnimation("Attack", AnimInfo, 1, 0.25f);

	vector<string> VecAnim04;
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⠶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣟⣳⢦⣀⣀⠘⢷⡰⣈⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡳⣏⢿⣹⣟⣛⠻⣤⢛⣇⠀⣠⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣜⠣⠌⠃⠐⠬⡀⢡⠘⣧⠎⣷⢯⡛⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⡰⠂⠀⢀⠳⣝⡦⣥⣋⠇⣲⠻⣤⣾⣻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠞⣹⢟⣀⡼⣟⣻⠟⠰⠿⠶⢯⡱⢣⠐⠌⠰⣻⢼⡳⣭⡐⡀⢆⡙⢶⣻⡦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡵⣞⣥⡞⢯⢟⡁⠀⣠⠀⠀⢀⡴⠋⢧⠣⢌⢶⡹⢖⡹⢒⡵⡈⠆⣼⢫⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣷⣤⡜⣭⠍⡶⠉⠰⢸⣇⠞⣹⣥⡔⢋⢠⡱⢯⣇⣞⡳⣛⢮⡒⣭⢸⡁⠎⣸⢿⡍⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣹⣾⢿⣙⣮⢳⡁⠀⠀⠚⡔⢣⡖⡍⠦⢃⠔⣣⠾⣼⣹⣱⣎⠷⡈⢇⡰⢁⡘⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡯⢿⡼⣧⣛⡶⣰⢧⡜⡧⣞⡱⢧⡧⣶⡹⣋⢶⣣⢳⡉⠖⡡⢂⠔⡠⣜⠝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⣙⠣⢟⡳⠽⢾⡹⠷⡭⢏⠷⡹⢦⠳⡝⢮⠵⡓⢎⢳⣐⣋⡴⡕⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠳⠚⠶⠛⠖⠳⠳⠞⠞⠶⠳⠚⠗⠞⠶⠓⠛⠞⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim04);
	Monster::animator->CreateAnimation("GetAttack", AnimInfo, 1, 0.25f);

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
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⣿⡟⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⢊⡽⢳⣶⡀⣠⢶⣶⢯⣿⣍⠳⣄⢠⣄⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⢰⠿⠞⡩⣳⢟⡏⣦⣻⢿⣾⣏⡱⣿⡷⢀⠼⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠝⠃⡀⣴⣙⣧⡟⣾⢷⡟⠿⢮⡽⣖⡛⡴⢣⡞⢧⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠾⡥⣏⣳⡝⢮⣛⠶⣹⣃⣻⣴⠤⡌⠑⣬⣱⣹⣋⠷⢦⣀⡻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠸⠖⠻⠓⠋⠉⠉⠉⠖⠞⠋⠉⠉⠉⠱⠞⠶⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim05);
	Monster::animator->CreateAnimation("Die", AnimInfo, 1, 0.25f);
}


double PoisonSlime::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
	return GetDamage() * GetSkillDamage();
}

void PoisonSlime::Attack()
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
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "스킬 공격 히트!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
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
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "일반 공격 히트! ", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(int(damage)) + "받았습니다!.", true, 0, TEXT_COLOR_TYPE::RED));
		}
		else { WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 일반 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY)); }
	}

}

void PoisonSlime::GetAttack()
{
	Monster::animator->Play("GetAttack", false);
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void PoisonSlime::DropItem() {
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

bool PoisonSlime::is_Die()
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
const string PoisonSlime::GetName()
{
	return SlimeStat.name;
}
const double PoisonSlime::GetCurrentHP()
{
	return SlimeStat.currentHp;
}
const double PoisonSlime::GetMaxHP()
{
	return SlimeStat.maxHp;
}
const double PoisonSlime::GetDropRate()
{
	return SlimeStat.dropRate;
}

const bool PoisonSlime::GetbDead()
{
	return bDead;
}

const int PoisonSlime::GetCoin()
{
	return SlimeStat.coin;
}
const int PoisonSlime::GetDefense()
{
	return SlimeStat.defense;
}
const int PoisonSlime::GetExp()
{
	return SlimeStat.exp;
}
const int PoisonSlime::GetEvasion()
{
	return SlimeStat.evasion;
}

const double PoisonSlime::GetSkillDamage()
{
	return SlimeStat.skillDamage;
}

const double PoisonSlime::GetDamage()
{
	return SlimeStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void PoisonSlime::SetCurrentHP(double hp)
{
	SlimeStat.currentHp = hp;
}
