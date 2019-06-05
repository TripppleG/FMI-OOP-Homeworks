#pragma once
#include "Club.h"

class PopFolkClub : virtual public Club
{
private:
	int capacity;
	char* singerName;

	void SetWhiskeyPrice(double);
	void SetVodkaPrice(double);
	void SetSingerName(const char*);

	void CopyFrom(const PopFolkClub&);
	void Free();
public:
	PopFolkClub(const char*, double, double, const char*);
	PopFolkClub(const PopFolkClub&);
	PopFolkClub& operator=(const PopFolkClub&);
	~PopFolkClub();
	Club* Clone() const;

	const char* GetMusicType() const;
	int GetCapacity() const;
	double GetWhiskeyPrice() const;
	double GetVodkaPrice() const;
	const char* GetSingerName() const;
	void AddUser(const User&);
};