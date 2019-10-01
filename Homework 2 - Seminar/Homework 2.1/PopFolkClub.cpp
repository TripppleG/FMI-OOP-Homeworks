#include "PopFolkClub.h"

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
	users = new User[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		users[i] = other.users[i];
	}
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	SetSingerName(other.singerName);
	capacity = other.capacity;
}

void PopFolkClub::Free()
{
	capacity = 0;
	whiskeyPrice = 0;
	vodkaPrice = 0;
	delete[] singerName;
}

PopFolkClub::PopFolkClub(const char* name, double whiskeyPrice, double vodkaPrice, const char* singerName) : Club(name, whiskeyPrice, vodkaPrice)
{
	capacity = 70;
	users = new User[capacity];
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
	SetSingerName(singerName);
}

PopFolkClub::PopFolkClub(const PopFolkClub& other) : Club(other)
{
	CopyFrom(other);
}

PopFolkClub& PopFolkClub::operator=(const PopFolkClub& other)
{
	if (this != &other)
	{
		Free();
		Club::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

PopFolkClub::~PopFolkClub()
{
	Free();
}

Club* PopFolkClub::Clone() const
{
	Club* copy = new PopFolkClub(*this);
	return copy;
}

const char* PopFolkClub::GetMusicType() const
{
	return "Pop-Folk";
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

void PopFolkClub::AddUser(const User& user)
{
	users[usersInClub] = user;
	usersInClub++;
}
