#pragma once
#include "TypeOfClub.h"
#include "User.h"
#include "HouseClub.h"
#include "PopFolkClub.h"
#include "RockClub.h"

class ClubsAndUsers : public User, public RockClub, public HouseClub, public PopFolkClub
{
	TypeOfClub** clubs;
	User* users;

	bool AddPopFolkClub(const char*, double, double, const char*);
	bool AddHouseClub(const char*, double, double, int);
	bool AddRockClub(const char*, double, double);

	bool AddToClub(const User&, const char*);
	bool RemoveFromClub(const char*, const char*);
};