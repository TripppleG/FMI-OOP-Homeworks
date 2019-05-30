#include "HouseClub.h"

void HouseClub::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid Name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void HouseClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 40)
	{
		throw "Invalid Whiskey Price!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void HouseClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 30)
	{
		throw "Invalid Vodka Price!";
	}
	this->vodkaPrice = vodkaPrice;
}

void HouseClub::SetNumberOfDJs(int numberOfDJs)
{
	if (numberOfDJs < 1)
	{
		throw "Invalid Number Of DJs!";
	}
	this->numberOfDJs = numberOfDJs;
}

void HouseClub::Resize()
{
	capacity *= 2;
}

void HouseClub::CopyFrom(const HouseClub& other)
{
	SetName(other.name);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	SetNumberOfDJs(other.numberOfDJs);
	capacity = other.capacity;
}

void HouseClub::Free()
{
	delete[] name;
	capacity = 0;
	whiskeyPrice = 0;
	vodkaPrice = 0;
	numberOfDJs = 0;
}

HouseClub::HouseClub(const char* name, double whiskeyPrice, double vodkaPrice, int numberOfDJs) : TypeOfClub(name)
{
	SetName(name);
	capacity = 1;
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
	SetNumberOfDJs(numberOfDJs);
}

HouseClub::HouseClub(const HouseClub& other) : TypeOfClub(other)
{
	CopyFrom(other);
}

HouseClub& HouseClub::operator=(const HouseClub& other)
{
	if (this != &other)
	{
		Free();
		TypeOfClub::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

HouseClub::~HouseClub()
{
	Free();
}

TypeOfClub* HouseClub::Clone()
{
	HouseClub* copy = new HouseClub(*this);
	return copy;
}

const char* HouseClub::GetName() const
{
	return name;
}

double HouseClub::GetWhiskeyPrice() const
{
	return whiskeyPrice;
}

double HouseClub::GetVodkaPrice() const
{
	return vodkaPrice;
}

int HouseClub::GetNumberOfDJs() const
{
	return numberOfDJs;
}
