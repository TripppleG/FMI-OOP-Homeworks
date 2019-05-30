#pragma once
#include <iostream>

class TypeOfClub
{
protected:
	char* name;
	int usersInClub;

	void SetName(const char*);

	void CopyFrom(const TypeOfClub&);
	void Free();
public:
	TypeOfClub(const char*);
	TypeOfClub(const TypeOfClub&);
	TypeOfClub& operator=(const TypeOfClub&);
	virtual ~TypeOfClub();
	virtual TypeOfClub* Clone() = 0;

	const char* GetName() const;
	int GetUsersInClub() const;
};