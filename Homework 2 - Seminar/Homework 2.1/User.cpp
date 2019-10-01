#include "User.h"

void User::SetName(const char* name)
{
	int len = strlen(name);
	if (len == 0)
	{
		throw "Invalid name!";
	}
	for (int i = 0; i < len; i++)
	{
		if (name[i] >= '0' && name[i] <= '9')
		{
			throw "Invalid name!";
		}
	}
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}

void User::SetAge(int age)
{
	if (age <= 0 || age > 130) // The oldest person ever lived died at the age of 122
	{
		throw "Invalid Age!";
	}
	this->age = age;
}

void User::SetBudget(double budget)
{
	if (budget < 0)
	{
		throw "Invalid Budget!";
	}
	this->budget = budget;
}

void User::SetNumberOfWhiskeysToDrink(int numberOfWhiskeysToDrink)
{
	if (numberOfWhiskeysToDrink < 0)
	{
		throw "Invalid Number Of Whiskeys!";
	}
	this->numberOfWhiskeysToDrink = numberOfWhiskeysToDrink;
}

void User::SetNumberOfVodkasToDrink(int numberOfVodkasToDrink)
{
	if (numberOfVodkasToDrink < 0)
	{
		throw "Invalid Number Of Vodkas!";
	}
	this->numberOfVodkasToDrink = numberOfVodkasToDrink;
}

void User::SetPreferedMusic(const char* preferedMusic)
{
	int len = strlen(preferedMusic);
	if (strcmp(preferedMusic, "Pop-Folk") && strcmp(preferedMusic, "House") && strcmp(preferedMusic, "Rock") && strcmp(preferedMusic, "Everything"))
	{
		throw "Invalid Prefered Music!";
	}
	this->preferedMusic = new char[len + 1];
	strcpy_s(this->preferedMusic, len + 1, preferedMusic);
}

void User::CopyFrom(const User& other)
{
	SetName(other.name);
	SetAge(other.age);
	SetBudget(other.budget);
	SetNumberOfWhiskeysToDrink(other.numberOfWhiskeysToDrink);
	SetNumberOfVodkasToDrink(other.numberOfVodkasToDrink);
	SetPreferedMusic(other.preferedMusic);
}

void User::Free()
{
	delete[] name;
	age = 0;
	budget = 0;
	numberOfWhiskeysToDrink = 0;
	numberOfVodkasToDrink = 0;
	delete[] preferedMusic;
}

User::User()
{
	name = new char[1];
	name[0] = '\0';
	age = 0;
	budget = 0;
	numberOfVodkasToDrink = 0;
	numberOfWhiskeysToDrink = 0;
	preferedMusic = new char[1];
	preferedMusic[0] = '\0';
}

User::User(const char* name, int age, double budget, int numberOfWhiskeysToDrink, int numberOfVodkasToDrink, const char* preferedMusic)
{
	SetName(name);
	SetAge(age);
	SetBudget(budget);
	SetNumberOfWhiskeysToDrink(numberOfWhiskeysToDrink);
	SetNumberOfVodkasToDrink(numberOfVodkasToDrink);
	SetPreferedMusic(preferedMusic);
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

const char* User::GetName() const
{
	return name;
}

int User::GetAge() const
{
	return age;
}

double User::GetBudget() const
{
	return budget;
}

int User::GetNumberOfWhiskeysToDrink() const
{
	return numberOfWhiskeysToDrink;
}

int User::GetNumberOfVodkasToDrink() const
{
	return numberOfVodkasToDrink;
}

const char* User::GetPreferedMusic() const
{
	return preferedMusic;
}