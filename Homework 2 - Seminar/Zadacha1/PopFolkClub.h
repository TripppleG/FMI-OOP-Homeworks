#pragma once
#include "Club.h"

class PopFolkClub : public Club
{
private:
	char* name;
	const int capacity = 70;
	int vodkaPrice;
	int whiskeyPrice;
	char* singer;

	void SetName(const char*);
	void SetVodkaPrice(double);
	void SetWhiskeyPrice(double);
	void SetSinger(const char*);

	void CopyFrom(const PopFolkClub&);
	void Free();
public:
	PopFolkClub();
	PopFolkClub(const char*, int, int, const char*);
	PopFolkClub(const PopFolkClub&);
	PopFolkClub& operator=(const PopFolkClub&);
	~PopFolkClub();
	Club* Clone();
};