#include "Club.h"

void Club::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid Name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void Club::CopyFrom(const Club& other)
{
	SetName(other.name);
	usersInClub = other.usersInClub;
}

void Club::Free()
{
	delete[]name;
	delete[] users;
	usersInClub = 0;
}

Club::Club(const char* name, double whiskeyPrice, double vodkaPrice)
{
	SetName(name);
	usersInClub = 0;
}

Club::Club(const Club& other)
{
	CopyFrom(other);
}

Club& Club::operator=(const Club& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Club::~Club()
{
	Free();
}

const char* Club::GetName() const
{
	return name;
}

int Club::GetUsersInClub() const
{
	return usersInClub;
}

bool Club::RemoveUser(const char* userName)
{
	for (int i = 0; i < usersInClub; i++)
	{
		if (!strcmp(users[i].GetName(), userName))
		{
			for (int j = i; j < usersInClub; j++)
			{
				users[i] = users[i + 1];
			}
			usersInClub--;
			return true;
		}
	}
	return false;
}
