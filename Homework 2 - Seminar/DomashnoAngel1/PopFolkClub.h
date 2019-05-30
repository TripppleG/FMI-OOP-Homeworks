#pragma once
#include "TypeOfClub.h"

class PopFolkClub : public TypeOfClub
{
private:
	char* name;
	int capacity;
	double whiskeyPrice;
	double vodkaPrice;
	char* singerName;

	void SetName(const char*);
	void SetWhiskeyPrice(double);
	void SetVodkaPrice(double);
	void SetSingerName(const char*);

	void CopyFrom(const PopFolkClub&);
	void Free();
public:
	PopFolkClub(const char*, double, double);
	PopFolkClub(const PopFolkClub&);
	PopFolkClub& operator=(const PopFolkClub&);
	~PopFolkClub();
	TypeOfClub* Clone();

	const char* GetName() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
	const char* GetSingerName() const;
};