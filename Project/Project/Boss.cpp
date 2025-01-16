#include "pch.h"
#include "Boss.h"


Boss::Boss()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(30, 40);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (8 * playerLevel);
	RandomManager::GetInstance()->setRange(7, 9);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (3 * playerLevel);
	int		def = playerLevel * 1;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	BossStat = { "🌈레인보우 드래곤🐉", Hp, Hp, damage, def, 1.4, 20, 30, 13, 20};
	dropItems[HEALTH_POTION] = BossStat.dropRate;
	dropItems[POWER_POTION] = BossStat.dropRate;
	bDead = false;
}

Boss::~Boss() {}

void Boss::Begin()
{
	CreateAnimations();
	Monster::animator->Play("Idle", true);
}

void Boss::Tick()
{
	Monster::Tick();
	//if (bDead == false && Monster::animator->isCurAnimEnd()) {
	//	//Monster::animator->Play("Idle", true);
	//}
}
void Boss::CreateAnimations()
{
	vector<string>VecAnim01;
	VecAnim01.push_back("");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⡀⠀⠀⠀⠀⠀⠀⠀⣄⡀⣠⣷⣄⠄⠀⠀⠀⢠⣧⡂⠀⠀⠀ ");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⢬⣦⢶⢷⢦⣿⡀⡀⡀⠀⠀⡀⣄⡾⡟⣿⣆⢝⢿⣤⣷⣟⢿⣽⡏⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⣰⣼⠣⣷⢷⡕⡍⢿⡞⠄⠀⢠⣙⢙⣷⣵⡢⡛⣷⡑⣿⣪⡿⠫⠉⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠈⠺⡯⣧⠿⢻⡎⡎⣿⠀⢀⠈⣽⢟⢕⢍⠻⡷⡝⡟⠼⢿⣇⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⠀⠈⠀⡡⣾⢇⢇⣿⠀⠐⢻⡾⡱⡱⣽⢣⢣⢣⣿⣻⡎⣿⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⡀⣄⣷⢻⢱⢱⣽⠃⠀⠰⡼⣗⢕⢕⢽⣇⢇⢇⡻⡹⡨⣿⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⣴⢞⢏⢎⢎⢎⣾⠑⠀⠀⢀⣈⣿⡸⡸⡨⣿⢳⣕⢿⡜⡌⢿⣆⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠠⣽⢫⢪⣪⣮⣮⢿⢷⢾⢮⣮⣬⣍⢽⡎⡎⡎⡞⣯⣷⣝⣷⢱⢱⡟⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⢱⡟⡞⣿⣽⣼⢾⠾⢷⢻⠷⠷⡷⡿⣿⣷⣧⡣⡣⣻⣿⣅⠻⢛⠫⠈⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⢸⣇⢇⢲⣿⣜⣜⢜⠵⡟⡟⡟⡜⡜⡜⣼⡽⡫⡪⣪⣷⢿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⢿⣜⢜⢜⣼⣿⣱⡱⡹⡻⣪⣪⣾⢞⢏⢎⣎⣎⢮⡷⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠛⢷⣽⠣⡍⡝⣿⣛⢛⢏⢏⢎⢎⢮⡟⡍⡻⣿⡱⣽⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⠀⢿⣕⢕⢕⡽⡾⣮⣮⣪⣪⣪⣺⣷⣕⢕⢽⣾⣯⣠⣀⣀⡀⠀⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⠀⠈⠙⠷⠷⣧⣣⣳⢟⣝⢻⣯⣫⣎⣿⣧⢩⢣⡭⣽⡟⣏⢟⣧⠀⠀⠀⠀⠀");
	VecAnim01.push_back("            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠻⠳⠻⢛⠃⠁⠁⠂⠛⠗⠏⠉⢚⠛⠟⠟⠏⠀⠀⠀");
	
	vector<vector<string >> AnimInfo;
	AnimInfo.push_back(VecAnim01);
	Monster::animator->CreateAnimation("Idle", AnimInfo, 1, 0.15f);
}

double Boss::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
	return GetDamage() * GetSkillDamage();
}

void Boss::Attack()
{
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

void Boss::GetAttack()
{
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void Boss::DropItem() {
	for (const auto& item : dropItems) {
		RandomManager::GetInstance()->setRange(0, 100);  // 0.0 ~ 1.0 사이의 랜덤 값
		double randomChance = RandomManager::GetInstance()->getRandom<double>();
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


bool Boss::is_Die()
{
	if (GetCurrentHP() <= 0) {
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
const string Boss::GetName()
{
	return BossStat.name;
}
const double Boss::GetCurrentHP()
{
	return BossStat.currentHp;
}
const double Boss::GetMaxHP()
{
	return BossStat.maxHp;
}
const double Boss::GetDropRate()
{
	return BossStat.dropRate;
}

const bool Boss::GetbDead()
{
	return bDead;
}

const int Boss::GetCoin()
{
	return BossStat.coin;
}
const int Boss::GetDefense()
{
	return BossStat.defense;
}
const int Boss::GetExp()
{
	return BossStat.exp;
}
const int Boss::GetEvasion()
{
	return BossStat.evasion;
}

const double Boss::GetSkillDamage()
{
	return BossStat.skillDamage;
}

const double Boss::GetDamage()
{
	return BossStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void Boss::SetCurrentHP(double hp)
{
	BossStat.currentHp = hp;
}



