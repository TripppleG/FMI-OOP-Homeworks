#include "RockClub.h"

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
	users = new User[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		users[i] = other.users[i];
	}
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	capacity = other.capacity;
}

void RockClub::Free()
{
	capacity = 0;
	whiskeyPrice = 0;
	vodkaPrice = 0;
}

RockClub::RockClub(const char* name, double whiskeyPrice, double vodkaPrice) : Club(name, whiskeyPrice, vodkaPrice)
{
	capacity = 30;
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
}

RockClub::RockClub(const RockClub& other) : Club(other)
{
	CopyFrom(other);
}

RockClub& RockClub::operator=(const RockClub& other)
{
	if (this != &other)
	{
		Free();
		Club::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

RockClub::~RockClub()
{
	Free();
}

Club* RockClub::Clone() const
{
	Club* copy = new RockClub(*this);
	return copy;
}

const char* RockClub::GetMusicType() const
{
	return "Rock";
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

void RockClub::AddUser(const User& user)
{
	users[usersInClub] = user;
	usersInClub++;
}