#include "RockClub.h"

void RockClub::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		this->name[0] = '\0';
		throw "Invalid name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void RockClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 40)
	{
		this->vodkaPrice = 40;
		throw "Invalid price of vodka!";
	}
	this->vodkaPrice = vodkaPrice;
}

void RockClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 30)
	{
		this->whiskeyPrice = 30;
		throw "Invalid price of whiskey!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void RockClub::CopyFrom(const RockClub& other)
{
	SetName(other.name);
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);
}

void RockClub::Free()
{
	delete[]name;
	vodkaPrice = 0;
	whiskeyPrice = 0;
}

RockClub::RockClub(){}

RockClub::RockClub(const char* name, int vodkaPrice, int whiskeyPrice) : Club(name)
{
	SetName(name);
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
}

RockClub::RockClub(const RockClub& other)
{
	CopyFrom(other);
}

RockClub& RockClub::operator=(const RockClub& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

RockClub::~RockClub()
{
	Free();
}

Club* RockClub::Clone()
{
	RockClub* copy = new RockClub(*this);
	return copy;
}
