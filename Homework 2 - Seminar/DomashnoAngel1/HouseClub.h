#pragma once
#include "TypeOfClub.h"

class HouseClub : public TypeOfClub
{
private:
	char* name;
	int capacity;
	double whiskeyPrice;
	double vodkaPrice;
	int numberOfDJs;

	void SetName(const char*);
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
	TypeOfClub* Clone();

	const char* GetName() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
	int GetNumberOfDJs() const;
};