#include "Cards.h"

void Card::SetName(const char* name)
{
	int len = strlen(name);
	if (len > 25 || len == 0)
	{
		strcpy_s(this->name, "Token");
	}
	else
	{
		strcpy_s(this->name, name);
	}
}

const char* Card::GetName() const
{
	return name;
}

void Card::SetAttPts(int attackPoints)
{
	if (attackPoints < 0 || attackPoints > 5000)
	{
		attackPoints = 0;
	}
	this->attackPoints = attackPoints;
}

int Card::GetAttPts() const
{
	return attackPoints;
}

void Card::SetDefPts(int defencePoints)
{
	if (defencePoints < 0 || defencePoints > 5000)
	{
		defencePoints = 0;
	}
	this->defencePoints = defencePoints;
}

int Card::GetDefPts() const
{
	return defencePoints;
}

void Card::MakeItMonster(bool isMonster)
{
	this->isMonster = isMonster;
}

bool Card::IsItMonster() const
{
	return isMonster;
}
