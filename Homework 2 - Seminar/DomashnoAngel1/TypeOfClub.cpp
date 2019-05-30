#include "TypeOfClub.h"

void TypeOfClub::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid Name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void TypeOfClub::CopyFrom(const TypeOfClub& other)
{
	SetName(other.name);
	usersInClub = other.usersInClub;
}

void TypeOfClub::Free()
{
	delete[]name;
	usersInClub = 0;
}

TypeOfClub::TypeOfClub(const char* name)
{
	SetName(name);
}

TypeOfClub::TypeOfClub(const TypeOfClub& other)
{
	CopyFrom(other);
}

TypeOfClub& TypeOfClub::operator=(const TypeOfClub& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

TypeOfClub::~TypeOfClub()
{
	Free();
}

const char* TypeOfClub::GetName() const
{
	return name;
}

int TypeOfClub::GetUsersInClub() const
{
	return usersInClub;
}
