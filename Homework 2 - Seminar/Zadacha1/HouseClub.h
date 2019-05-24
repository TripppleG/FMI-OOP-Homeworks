#pragma once
#include "Club.h"

class HouseClub : public Club
{
private:
	char* name;
	const int capacity = 10'000'000;
	int vodkaPrice;
	int whiskeyPrice;
	int numberOfDJs;

	void SetName(const char*);
	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);
	void SetNumberOfDJs(int);

	void CopyFrom(const HouseClub&);
	void Free();
public:
	HouseClub();
	HouseClub(const char*, int, int);
	HouseClub(const HouseClub&);
	HouseClub& operator=(const HouseClub&);
	~HouseClub();
	Club* Clone();
};