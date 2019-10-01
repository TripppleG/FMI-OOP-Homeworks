#pragma once
#include "Club.h"

class HouseClub : virtual public Club
{
private:
	int capacity;
	int numberOfDJs;

	void SetWhiskeyPrice(double);
	void SetVodkaPrice(double);
	void SetNumberOfDJs(int);

	void Resize();
	void CopyFrom(const HouseClub&);
	void Free();
public:
	HouseClub(const char*, double, double, int);
	HouseClub(const HouseClub&);
	HouseClub& operator=(const HouseClub&);
	~HouseClub();

	const char* GetMusicType() const;
	const char* GetName() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
	Club* Clone() const;
	void AddUser(const User&);
};