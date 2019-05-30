#pragma once
#include "TypeOfClub.h"

class RockClub : public TypeOfClub
{
private:
	char* name;
	int capacity;
	double whiskeyPrice;
	double vodkaPrice;
	
	void SetName(const char*);
	void SetWhiskeyPrice(double);
	void SetVodkaPrice(double);

	void CopyFrom(const RockClub&);
	void Free();
public:
	RockClub(const char*, double, double);
	RockClub(const RockClub&);
	RockClub& operator=(const RockClub&);
	~RockClub();
	TypeOfClub* Clone();

	const char* GetName() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
};