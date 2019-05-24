#include "User.h"

void User::setName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		if ((name[i] >= '0' && name[i] <= '9') || len == 0)
		{
			this->name[0] = '\0';
			throw "Invalid name!";
		}
	}
	strcpy_s(this->name, len + 1, name);
}

void User::setAge(int age)
{
	if (age < 0 || age > 110)
	{
		this->age = 0;
		throw "Invalid age!";
	}
	this->age = age;
}

void User::setBudget(double budget)
{
	if (budget < 0)
	{
		this->budget = 0;
		throw "Invalid budget!";
	}
	this->budget = budget;
}

void User::setNumberOfWhiskeys(int numberOfWhiskeys)
{
	if (numberOfWhiskeys < 0)
	{
		numberOfWhiskeys = 0;
		throw "Invalid number of whiskeys!";
	}
	this->numberOfWhiskeys = numberOfWhiskeys;
}

void User::setNumberOfVodkas(int numberOfVodkas)
{
	if (numberOfVodkas < 0)
	{
		numberOfVodkas = 0;
		throw "Invalid number of vodkas!";
	}
	this->numberOfVodkas = numberOfVodkas;
}

void User::setMusicGenre(int musicGenre)
{
	switch (musicGenre)
	{
	case 1:
		this->musicGenre = 1;
		break;
	case 2:
		this->musicGenre = 2;
		break;
	case 3:
		this->musicGenre = 3;
		break;
	case 4:
		this->musicGenre = 4;
		break;
	default:
		this->musicGenre = 0;
		throw "Invalid Music Genre";
		break;
	}
}

void User::CopyFrom(const User& other)
{
	setName(other.name);
	setAge(other.age);
	setBudget(other.budget);
	setNumberOfVodkas(other.numberOfVodkas);
	setNumberOfWhiskeys(other.numberOfWhiskeys);	
}

void User::Free()
{
	delete[] name;
	age = 0;
	budget = 0;
	numberOfWhiskeys = 0;
	numberOfVodkas = 0;
}


User::User(){}

User::User(const char* name, int age, double budget, int numberOfWhiskeys, int numberOfVodkas, int musicGenre)
{
	setName(name);
	setAge(age);
	setBudget(budget);
	setNumberOfWhiskeys(numberOfWhiskeys);
	setNumberOfVodkas(numberOfVodkas);
	setMusicGenre(musicGenre);
}

User::User(const User& other)
{
	CopyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

User::~User()
{
	Free();
}