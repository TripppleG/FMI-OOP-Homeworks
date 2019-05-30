#include "RockClub.h"

void RockClub::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid Name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void RockClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 30)
	{
		throw "Invalid Whiskey Price!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void RockClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 40)
	{
		throw "Invalid Vodka Price!";
	}
	this->vodkaPrice = vodkaPrice;
}

void RockClub::CopyFrom(const RockClub& other)
{
	SetName(other.name);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	capacity = other.capacity;
}

void RockClub::Free()
{
	delete[] name;
	capacity = 0;
	whiskeyPrice = 0;
	vodkaPrice = 0;
}

RockClub::RockClub(const char* name, double whiskeyPrice, double vodkaPrice) : TypeOfClub(name)
{
	SetName(name);
	capacity = 30;
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
}

RockClub::RockClub(const RockClub& other) : TypeOfClub(other)
{
	CopyFrom(other);
}

RockClub& RockClub::operator=(const RockClub& other)
{
	if (this != &other)
	{
		Free();
		TypeOfClub::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

RockClub::~RockClub()
{
	Free();
}

TypeOfClub* RockClub::Clone()
{
	TypeOfClub* copy = new RockClub(*this);
	return copy;
}

const char* RockClub::GetName() const
{
	return name;
}

int RockClub::GetCapacity() const
{
	return capacity;
}

double RockClub::GetWhiskeyPrice() const
{
	return whiskeyPrice;
}

double RockClub::GetVodkaPrice() const
{
	return vodkaPrice;
}
