#pragma once
#include "User.h"

class Club
{
private:
	void SetName(const char*);
	virtual void SetWhiskeyPrice(double) = 0;
	virtual void SetVodkaPrice(double) = 0;

	void CopyFrom(const Club&);
	void Free();
protected:
	char* name;
	User* users;
	double whiskeyPrice;
	double vodkaPrice;
	int usersInClub;
public:
	Club(const char*, double, double);
	Club(const Club&);
	Club& operator=(const Club&);
	virtual ~Club();

	virtual const char* GetMusicType() const = 0;
	virtual int GetCapacity() const = 0;
	virtual double GetWhiskeyPrice() const = 0;
	virtual double GetVodkaPrice() const = 0;
	const char* GetName() const;
	int GetUsersInClub() const;

	virtual Club* Clone() const = 0;
	virtual void AddUser(const User&) = 0;
	bool RemoveUser(const char*);
};