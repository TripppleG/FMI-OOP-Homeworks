#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

class Card
{
private:
	char name[26];
	bool isMonster = false;
	int attackPoints;
	int defencePoints;
public:
	void SetName(const char*);
	const char* GetName() const;

	void SetAttPts(int);
	int GetAttPts() const;

	void SetDefPts(int);
	int GetDefPts() const;

	void MakeItMonster(bool);
	bool IsItMonster() const;
};