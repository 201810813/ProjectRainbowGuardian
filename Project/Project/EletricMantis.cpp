#include "pch.h"
#include "EletricMantis.h"


EletricMantis::EletricMantis()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>() + (6 *playerLevel));
	RandomManager::GetInstance()->setRange(5, 7);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>() + (2* playerLevel));
	int		def = playerLevel * 2;
					//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	MantisStat = { "전기사마귀",Hp,Hp,damage,def,1.4,20,30,13,20};
	dropItems[HEALTH_POTION] = MantisStat.dropRate;
	dropItems[POWER_POTION] = MantisStat.dropRate;
	bDead = false;
	CreateAnimations();
	Monster::animator->Play("Idle", true);
}

EletricMantis::~EletricMantis() {}

void EletricMantis::Begin()
{
}

void EletricMantis::Tick()
{
	Monster::Tick();
	if (bDead == false && Monster::animator->isCurAnimEnd()) {
		Monster::animator->Play("Idle", true);
	}
}

void EletricMantis::CreateAnimations()
{
	vector<string> VecAnim01;
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⣤⣛⢧⣆⠀⠀⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣯⢻⡼⣣⢯⣟⡿⣼⣄⠀⠀⠀⢀⣀⠖⣽⠆⠀⠀⣀⢔⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⢿⣻⢷⣹⢳⣟⣾⢻⣽⣻⡆⠀⢨⣜⣤⣿⣻⣀⠖⣋⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⡿⣯⢟⣯⠷⣯⠛⡂⣽⣿⣇⣇⡴⣯⣾⢿⣋⣥⠞⡻⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢠⠥⣍⢓⠦⡀⠀⠀⠀⡿⡿⡦⠘⡟⠀⢂⡵⣽⣿⢻⣭⢿⣜⡶⢯⢭⡒⡭⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢎⢽⡉⠙⠺⣝⢦⡀⠀⠑⠁⢳⣆⡥⢢⢞⣴⠘⡧⢻⣼⢷⣫⣞⣳⠎⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢎⠦⠀⠀⣨⢣⢧⣄⡄⣠⣎⠾⢿⠾⣿⢿⣀⡷⣞⣿⣂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠃⠈⠃⠛⢯⣿⣻⡤⣬⢀⠀⠀⢿⠻⣽⣫⡏⠸⣟⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣙⠳⣟⣷⣏⢶⢣⠀⠀⠁⠉⠀⠀⠈⢷⣻⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠯⠴⠿⠿⠾⠏⠚⠛⠀⠀⠀⠀⠀⠀⠠⠾⠴⠯⠿⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	vector<string> VecAnim02;
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢶⣣⡴⣏⡷⣷⢿⣢⡀⠀⠀⠀⠀⢀⡤⣻⠆⠀⠀⠀⡠⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⣿⢿⣶⡹⣞⡽⣯⣟⣯⢿⡄⠀⢀⡼⣋⣴⡿⢁⡤⠖⣩⠜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⣞⡿⣞⡵⣯⠟⠇⣼⣿⡏⡇⣠⣞⣵⣿⠷⣛⡭⢶⡝⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢉⣋⡒⠦⣄⠀⠀⠀⠀⣷⣿⣌⠹⡻⠡⠌⢪⣹⣿⡿⣛⣷⡹⣭⣞⣛⠭⢒⡵⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡜⣲⠛⠺⢴⡳⣄⠀⠀⠣⠃⢧⡄⣃⠄⣜⣣⠹⣏⢼⣻⣼⠟⡵⢮⣜⠾⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡜⡇⠀⠀⢙⣎⣇⢀⡀⢀⡜⣹⡷⣼⣾⣿⠁⣏⡼⣿⠌⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠆⠐⠳⠺⣼⡿⣧⡍⣚⠁⠃⠀⣿⢾⡿⣝⡿⢹⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠷⣻⣯⣖⡤⣄⠈⠀⠛⠙⠃⠀⠘⢯⢿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim02.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠯⠴⠿⠷⠯⠗⠽⠾⠀⠀⠀⠀⠀⠀⠠⠮⠵⠮⠿⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	vector<vector<string>> AnimInfo;
	AnimInfo.push_back(VecAnim01);
	AnimInfo.push_back(VecAnim02);
	Monster::animator->CreateAnimation("Idle", AnimInfo, 2, 0.15f);

	vector<string> VecAnim03;
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⢤⡖⡶⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢚⣥⣚⣳⣎⠵⣋⡿⢮⣽⣤⡤⢄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⠘⢉⣠⠞⡽⣹⢾⣽⡻⢯⡷⢿⣹⣾⣝⡚⡜⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⢀⠦⠶⣜⣩⠶⢿⡹⣭⣟⢧⡟⣭⡛⣷⣻⢯⣟⡿⣿⣼⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⢀⠔⣥⣞⡝⠊⣁⠞⣥⡟⣽⠞⠫⠚⡁⠌⣣⣽⣧⢻⣿⠏⠃⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⢀⢔⡵⠛⠁⠀⠀⠀⠙⠪⢍⢙⢦⡌⠠⠃⣼⢹⡆⢙⣫⣾⣿⣿⣶⡦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢉⣯⠄⡞⣡⣾⣶⣿⣿⠟⠗⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⣀⠤⠤⣤⡀⠀⠀⠀⠀⢀⡞⣠⣾⠽⠛⠻⠿⢉⣀⢤⡼⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⣄⢢⣹⡴⠞⠶⢧⣣⢀⡀⣤⠴⣞⠾⡿⢲⡆⠀⠀⠀⣘⣯⡿⣽⡄⠐⠀⢀⢠⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠠⣃⠴⣫⠁⠀⠀⢀⡬⣳⢮⣽⢮⡿⡝⠳⠛⢳⣃⡿⣦⡿⡽⡇⢿⡏⠀⠀⠀⠀⠾⣟⣶⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠈⠒⠽⣳⣶⡄⠈⠁⠁⠀⠈⠛⠉⠀⠀⠀⠺⠿⠙⠁⠁⠀⠈⢮⡇⠀⠀⠀⠀⠀⠈⠈⠋⡟⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim03.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠠⠾⠾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim03);
	Monster::animator->CreateAnimation("Attack", AnimInfo, 1, 0.25f);

	vector<string> VecAnim04;
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⢯⣗⡮⢷⣴⡾⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡺⢛⣉⡥⢤⡄⡿⣝⣫⢷⣻⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢮⣱⢿⣫⣿⡱⣰⣟⡽⠞⣡⣟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⣤⢟⡚⢿⡳⣽⢞⡵⣷⣞⢣⣂⢵⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢟⣭⡷⣎⠟⠉⢉⣷⡍⣿⣷⣹⣯⢷⡌⢾⡋⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣞⣹⠼⣯⣾⠝⠁⠀⠀⣿⣬⡷⡌⣟⣦⢻⣟⣿⢷⠿⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠃⠀⠁⠀⠀⠀⠀⢰⣟⡾⢉⡿⣶⢿⣣⠸⣿⠂⠐⠾⣅⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⣿⢾⠁⠀⠀⠀⠀⠙⢦⡹⡀⠀⠀⠛⢿⣳⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim04.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠯⠴⠿⠯⠿⠇⠀⠀⠀⠀⠀⠀⠉⠚⠂⠀⠠⠾⠴⠾⠯⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

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
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣻⡿⣿⢶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡟⡶⣯⣟⣯⢿⡻⠽⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣯⣝⡳⣽⡾⣿⡐⣋⣾⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣭⠛⣿⢾⡽⣶⣻⠧⢰⡃⢻⡱⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣯⣿⣿⡓⣏⢧⡐⡙⢤⣓⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim05.push_back("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⠝⠀⠛⠼⠧⠿⠽⠶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

	AnimInfo.clear();
	AnimInfo.push_back(VecAnim05);
	Monster::animator->CreateAnimation("Die", AnimInfo, 1, 0.25f);
}



double EletricMantis::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0, TEXT_COLOR_TYPE::RED));
	return GetDamage() * GetSkillDamage();
}

void EletricMantis::Attack()
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
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "스킬 공격 히트! ", true, 0, TEXT_COLOR_TYPE::RED));
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
		else 
		{ 
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 일반 공격을 회피했습니다.", true, 0, TEXT_COLOR_TYPE::RED_INENSITY)); 
		}
	}

}

void EletricMantis::GetAttack()
{
	Monster::animator->Play("GetAttack", false);
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void EletricMantis::DropItem() {
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
				WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, droppedItem->GetName() + "이(가) 드롭되었습니다.", true, 0 , TEXT_COLOR_TYPE::GREEN));
			}
			delete droppedItem;
		}
	}
}



bool EletricMantis::is_Die()
{
	if (GetCurrentHP() <= 0) {
		Monster::animator->Play("Die", false);
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신이 전기 사마귀를 쓰러트렸습니다!", true, 0, TEXT_COLOR_TYPE::BLUE));
		DropItem();
		bDead = true;
		return bDead;
	}
	return bDead;
}



//---------------------------------
//           Get함수
//---------------------------------
const string EletricMantis::GetName()
{
	return MantisStat.name;
}
const double EletricMantis::GetCurrentHP()
{
	return MantisStat.currentHp;
}
const double EletricMantis::GetMaxHP()
{
	return MantisStat.maxHp;
}
const double EletricMantis::GetDropRate()
{
	return MantisStat.dropRate;
}

const bool EletricMantis::GetbDead()
{
	return bDead;
}

const int EletricMantis::GetCoin()
{
	return MantisStat.coin;
}
const int EletricMantis::GetDefense()
{
	return MantisStat.defense;
}
const int EletricMantis::GetExp()
{
	return MantisStat.exp;
}
const int EletricMantis::GetEvasion()
{
	return MantisStat.evasion;
}

const double EletricMantis::GetSkillDamage()
{
	return MantisStat.skillDamage;
}

const double EletricMantis::GetDamage()
{
	return MantisStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void EletricMantis::SetCurrentHP(double hp)
{
	MantisStat.currentHp = hp;
}



