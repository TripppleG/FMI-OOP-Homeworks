#pragma once
#include <fstream>

const short MAX_NAME_SIZE = 100;

class Player
{
	friend class BlackJack;
	char name[MAX_NAME_SIZE];
	unsigned age;
	unsigned wins;
	unsigned playedGames;
	double winCoef;

	void SetName(const char name[MAX_NAME_SIZE]);
	void SetAge(unsigned age);

public:
	Player() : name(""), age(0), wins(0), winCoef(0), playedGames(0) {}
	Player(const char name[MAX_NAME_SIZE], int age);

	const char* GetName()const;
	unsigned GetAge()const;
	unsigned GetWins()const;
	unsigned GetPlayedGames()const;
	double GetWinCoef()const;

	void Read(std::istream& is);
	void Write(std::ostream& os);
};