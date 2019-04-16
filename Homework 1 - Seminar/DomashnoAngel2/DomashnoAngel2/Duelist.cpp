#include "Duelist.h"

bool HasDigits(const char* name, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (name[i] >= '0' && name[i] <= '9')
		{
			true;
		}
	}
	return false;
}
Duelist::Duelist(const char* name)
{
	SetName(name);
}

Duelist::Duelist(const Duelist& other)
{
	CopyFrom(other);
}
 
Duelist& Duelist::operator=(const Duelist& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Duelist::~Duelist()
{
	Free();
}

void Duelist::ChangeDeck(short cardNumber, const char* cardName, int attPts, int defPts)
{
	deck.ChangeCard(cardNumber, cardName, attPts, defPts);
}

void Duelist::ChangeDeck(short cardNumber, const char* cardName)
{
	deck.ChangeCard(cardNumber, cardName);
}

void Duelist::SetName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len > 50 || len == 0 || HasDigits(name, len))
	{
		this->name[0] = '\0';
		return;
	}
	strcpy_s(this->name, len + 1, name);
}

char* Duelist::GetName()const
{
	return name;
}
