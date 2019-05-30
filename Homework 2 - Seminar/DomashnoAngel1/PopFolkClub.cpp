#include "PopFolkClub.h"

void PopFolkClub::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid Name!";
	}
	strcpy_s(this->name, len + 1, name);
}

void PopFolkClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 35)
	{
		throw "Invalid Whiskey Price!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void PopFolkClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 20)
	{
		throw "Invalid Vodka Price!";
	}
	this->vodkaPrice = vodkaPrice;
}

void PopFolkClub::SetSingerName(const char* singerName)
{
	int len = strlen(singerName);
	this->singerName = new char[len + 1];
	if (len == 0)
	{
		throw "Invalid name!";
	}
	strcpy_s(this->singerName, len + 1, singerName);
}

void PopFolkClub::CopyFrom(const PopFolkClub& other)
{
	SetName(other.name);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	SetSingerName(other.singerName);
	capacity = other.capacity;
}

void PopFolkClub::Free()
{
	delete[] name;
	capacity = 0;
	whiskeyPrice = 0;
	vodkaPrice = 0;
}

PopFolkClub::PopFolkClub(const char* name, double whiskeyPrice, double vodkaPrice) : TypeOfClub(name)
{
	SetName(name);
	capacity = 70;
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
}

PopFolkClub::PopFolkClub(const PopFolkClub& other) : TypeOfClub(other)
{
	CopyFrom(other);
}

PopFolkClub& PopFolkClub::operator=(const PopFolkClub& other)
{
	if (this != &other)
	{
		Free();
		TypeOfClub::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

PopFolkClub::~PopFolkClub()
{
	Free();
}

TypeOfClub* PopFolkClub::Clone()
{
	TypeOfClub* copy = new PopFolkClub(*this);
	return copy;
}

const char* PopFolkClub::GetName() const
{
	return name;
}

int PopFolkClub::GetCapacity() const
{
	return capacity;
}

double PopFolkClub::GetWhiskeyPrice() const
{
	return whiskeyPrice;
}

double PopFolkClub::GetVodkaPrice() const
{
	return vodkaPrice;
}

const char* PopFolkClub::GetSingerName() const
{
	return singerName;
}
