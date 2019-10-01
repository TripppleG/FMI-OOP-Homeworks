#pragma once
#include "User.h"
#include "HouseClub.h"
#include "PopFolkClub.h"
#include "RockClub.h"

class ClubCollection
{
	Club** clubs;
	int size;
	int clubsCount;
	int ClubIndex(const char*) const;

	void CopyFrom(const ClubCollection&);
	void Free();
	void Resize();

public:
	ClubCollection();
	ClubCollection(const ClubCollection&);
	ClubCollection& operator=(const ClubCollection&);
	~ClubCollection();

	bool AddPopFolkClub(const char*, double, double, const char*);
	bool AddRockClub(const char*, double, double);
	bool AddHouseClub(const char*, double, double, int);
	bool RemoveClub(const char*);
	bool AddToClub(User&, const char*);
	bool RemoveFromClub(const char*, const char*);
};