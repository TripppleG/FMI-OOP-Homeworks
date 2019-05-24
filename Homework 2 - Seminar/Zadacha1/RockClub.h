#pragma once
#include "Club.h"

class RockClub : public Club
{
private:
	char* name;
	const int capacity = 30;
	int vodkaPrice;
	int whiskeyPrice;

	void SetName(const char*);
	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);

	void CopyFrom(const RockClub&);
	void Free();
public:
	RockClub();
	RockClub(const char*, int, int);
	RockClub(const RockClub&);
	RockClub& operator=(const RockClub&);
	~RockClub();
	Club* Clone();
};