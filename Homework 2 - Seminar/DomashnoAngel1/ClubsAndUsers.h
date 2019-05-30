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

};