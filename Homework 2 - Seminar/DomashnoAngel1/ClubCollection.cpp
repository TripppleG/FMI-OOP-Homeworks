#include "ClubCollection.h"

int ClubCollection::ClubIndex(const char* clubName) const
{
	for (int i = 0; i < clubsCount; i++)
	{
		if (!strcmp(clubs[i]->GetName(), clubName))
		{
			return i;
		}
	}
	return -1;
}

void ClubCollection::CopyFrom(const ClubCollection& other)
{
	clubs = new Club*[other.size];
	size = other.size;
	clubsCount = other.clubsCount;
	for (int i = 0; i < clubsCount; i++)
	{
		clubs[i] = other.clubs[i]->Clone();
	}
}

void ClubCollection::Free()
{
	delete[] clubs;
	clubsCount = 0;
	size = 1;
}

void ClubCollection::Resize()
{
	Club** temp = new Club*[size * 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = clubs[i];
	}
	size *= 2;
	delete[] clubs;
	clubs = temp;
}

ClubCollection::ClubCollection()
{
	size = 1;
	clubsCount = 0;
	clubs = new Club*[size];
}

ClubCollection::ClubCollection(const ClubCollection& other)
{
	CopyFrom(other);
}

ClubCollection& ClubCollection::operator=(const ClubCollection& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

ClubCollection::~ClubCollection()
{
	Free();
}

bool ClubCollection::AddPopFolkClub(const char* name, double whiskeyPrice, double vodkaPrice, const char* singer)
{
	Club* club = new PopFolkClub(name, whiskeyPrice, vodkaPrice, singer);
	if (clubsCount == size)
	{
		Resize();
	}
	clubs[clubsCount] = club;
	clubsCount++;
	return true;
}

bool ClubCollection::AddRockClub(const char* name, double whiskeyPrice, double vodkaPrice)
{
	Club* club = new RockClub(name, whiskeyPrice, vodkaPrice);
	if (clubsCount == size)
	{
		Resize();
	}
	clubs[clubsCount] = club;
	clubsCount++;
	return true;
}

bool ClubCollection::AddHouseClub(const char* name, double whiskeyPrice, double vodkaPrice, int numberOfDJs)
{
	Club* club = new HouseClub(name, whiskeyPrice, vodkaPrice, numberOfDJs);
	if (clubsCount == size)
	{
		Resize();
	}
	clubs[clubsCount] = club;
	clubsCount++;
	return true;
}

bool ClubCollection::RemoveClub(const char* clubName)
{
	int i = ClubIndex(clubName);
	if (i == -1) // -1 if doesnt exist
	{
		return false;
	}
	for (int j = i; i < clubsCount; i++)
	{
		clubs[i] = clubs[i + 1];
	}
	clubsCount--;
	return true;
}

bool ClubCollection::AddToClub(User& user, const char* clubName)
{
	int i = ClubIndex(clubName);
	const char* musicType = clubs[i]->GetMusicType();
	double tempBudget = user.GetBudget();
	double neededMoney = user.GetNumberOfVodkasToDrink() * clubs[i]->GetVodkaPrice() + user.GetNumberOfWhiskeysToDrink() * clubs[i]->GetWhiskeyPrice();
	if (!strcmp(musicType, "Pop-Folk"))
	{
		if (user.GetAge() < 18)
		{
			tempBudget -= 20;
		}
		if (tempBudget < neededMoney || clubs[i]->GetCapacity() == clubs[i]->GetUsersInClub() || !strcmp(user.GetPreferedMusic(), "Rock"))
		{
			return false;
		}
		user.SetBudget(tempBudget - neededMoney);
		clubs[i]->AddUser(user);
		return true;
	}
	else if (!strcmp(musicType, "Rock"))
	{
		if (user.GetAge() < 18 || tempBudget < neededMoney || clubs[i]->GetCapacity() == clubs[i]->GetUsersInClub() || !strcmp(user.GetPreferedMusic(), "House"))
		{
			return false;
		}
		user.SetBudget(tempBudget - neededMoney);
		clubs[i]->AddUser(user);
		return true;
	}
	else if (!strcmp(musicType, "House"))
	{
		if (user.GetAge() < 18 || tempBudget < neededMoney || !strcmp(user.GetPreferedMusic(), "Pop-Folk"))
		{
			return false;
		}
		user.SetBudget(tempBudget - neededMoney);
		clubs[i]->AddUser(user);
		return true;
	}
	return false;
}

bool ClubCollection::RemoveFromClub(const char* userName, const char* clubName)
{
	int i = ClubIndex(clubName);
	if (i == -1) // -1 if doesnt exist
	{
		return false;
	}
	return clubs[i]->RemoveUser(userName);
}
