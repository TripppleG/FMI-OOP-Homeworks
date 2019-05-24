#include "HouseClub.h"

void HouseClub::SetName(const char* name)
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

void HouseClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 30)
	{
		this->vodkaPrice = 30;
		throw "Invalid price of vodka!";
	}
	this->vodkaPrice = vodkaPrice;
}

void HouseClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 40)
	{
		this->whiskeyPrice = 40;
		throw "Invalid price of whiskey!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void HouseClub::SetNumberOfDJs(int numberOfDJs)
{
	if (numberOfDJs < 1)
	{
		this->numberOfDJs = 1;
		throw "Invalid number of DJs!";
	}
	this->numberOfDJs = numberOfDJs;
}

void HouseClub::CopyFrom(const HouseClub& other)
{
	SetName(other.name);
	SetNumberOfDJs(other.numberOfDJs);
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);
}

void HouseClub::Free()
{
	delete[] name;
	vodkaPrice = 0;
	whiskeyPrice = 0;
	numberOfDJs = 0;
}

HouseClub::HouseClub(){}

HouseClub::HouseClub(const char* name, int vodkaPrice, int whiskeyPrice) : Club(name)
{
	SetName(name);
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
}

HouseClub::HouseClub(const HouseClub& other)
{
	CopyFrom(other);
}

HouseClub& HouseClub::operator=(const HouseClub& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

HouseClub::~HouseClub()
{
	Free();
}

Club* HouseClub::Clone()
{
	HouseClub* copy = new HouseClub(*this);
	return copy;
}
