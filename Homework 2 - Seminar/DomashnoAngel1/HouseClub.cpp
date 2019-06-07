#include "HouseClub.h"

void HouseClub::SetWhiskeyPrice(double whiskeyPrice)
{
	if (whiskeyPrice < 40)
	{
		throw "Invalid Whyskey Price!";
	}
	this->whiskeyPrice = whiskeyPrice;
}

void HouseClub::SetVodkaPrice(double vodkaPrice)
{
	if (vodkaPrice < 30)
	{
		throw "Invalid Whyskey Price!";
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
	User* temp = new User[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = users[i];
	}
	capacity *= 2;
	delete[] users;
	users = temp;
}

void HouseClub::CopyFrom(const HouseClub& other)
{
	users = new User[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		users[i] = other.users[i];
	}

	SetNumberOfDJs(other.numberOfDJs);
	SetWhiskeyPrice(other.whiskeyPrice);
	SetVodkaPrice(other.vodkaPrice);
	capacity = other.capacity;
}

void HouseClub::Free()
{
	capacity = 0;
	numberOfDJs = 0;
}

HouseClub::HouseClub(const char* name, double whiskeyPrice, double vodkaPrice, int numberOfDJs) : Club(name, whiskeyPrice, vodkaPrice)
{
	capacity = 1;
	users = new User[capacity];
	SetWhiskeyPrice(whiskeyPrice);
	SetVodkaPrice(vodkaPrice);
	SetNumberOfDJs(numberOfDJs);
}

HouseClub::HouseClub(const HouseClub& other) : Club(other)
{
	CopyFrom(other);
}

HouseClub& HouseClub::operator=(const HouseClub& other)
{
	if (this != &other)
	{
		Free();
		Club::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

HouseClub::~HouseClub()
{
	Free();
}

Club* HouseClub::Clone() const
{
	HouseClub* copy = new HouseClub(*this);
	return copy;
}

void HouseClub::AddUser(const User& user)
{
	if (usersInClub == capacity)
	{
		Resize();
	}
	users[usersInClub] = user;
	usersInClub++;
}

const char* HouseClub::GetMusicType() const
{
	return "House";
}

const char* HouseClub::GetName() const
{
	return name;
}

int HouseClub::GetCapacity() const
{
	return capacity;
}

double HouseClub::GetWhiskeyPrice() const
{
	return whiskeyPrice;
}

double HouseClub::GetVodkaPrice() const
{
	return vodkaPrice;
}
