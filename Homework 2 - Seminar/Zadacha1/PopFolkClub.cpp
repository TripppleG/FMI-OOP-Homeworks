#include "PopFolkClub.h"

void PopFolkClub::SetName(const char* name)
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

void PopFolkClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 20)
	{
		this->vodkaPrice = 20;
		throw "Invalid price of vodka!";
	}
	this->vodkaPrice = vodkaPrice;
}

void PopFolkClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 35)
	{
		this->whiskeyPrice = 35;
		throw "Invalid price of whiskey!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void PopFolkClub::SetSinger(const char* singer)
{
	int len = strlen(singer);
	this->singer = new char[len + 1];
	if (len == 0)
	{
		this->singer[0] = '\0';
		throw "Invalid name!";
	}
	strcpy_s(this->singer, len + 1, singer);
}

void PopFolkClub::CopyFrom(const PopFolkClub& other)
{
	SetName(other.name);
	SetVodkaPrice(other.vodkaPrice);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetSinger(other.singer);
}

void PopFolkClub::Free()
{
	delete[]name;
	whiskeyPrice = 0;
	vodkaPrice = 0;
	delete[]singer;
}

PopFolkClub::PopFolkClub(){}

PopFolkClub::PopFolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singer) : Club(name)
{
	SetName(name);
	SetVodkaPrice(vodkaPrice);
	SetWhiskeyPrice(whiskeyPrice);
	SetSinger(singer);
}

PopFolkClub::PopFolkClub(const PopFolkClub& other)
{
	CopyFrom(other);
}

PopFolkClub& PopFolkClub::operator=(const PopFolkClub& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

PopFolkClub::~PopFolkClub()
{
	Free();
}

Club* PopFolkClub::Clone()
{
	PopFolkClub* copy = new PopFolkClub(*this);
	return copy;
}