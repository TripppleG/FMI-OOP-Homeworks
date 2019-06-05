#pragma once
#include "Club.h"

class RockClub : virtual public Club
{
private:
	int capacity;
	double whiskeyPrice;
	double vodkaPrice;

	void SetWhiskeyPrice(double);
	void SetVodkaPrice(double);

	void CopyFrom(const RockClub&);
	void Free();
public:
	RockClub(const char*, double, double);
	RockClub(const RockClub&);
	RockClub& operator=(const RockClub&);
	~RockClub();
	Club* Clone() const;

	const char* GetMusicType() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
	void AddUser(const User&);
};