#pragma once
#include "Deck.h"

class Duelist
{
private:
	char* name;
	Deck deck;
	void CopyFrom(const Duelist& other)
	{
		int len = strlen(other.name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, other.name);
	}
	void Free()
	{
		delete[] name;
	}
public:
	Duelist(const char*);
	Duelist(const Duelist& other);
	Duelist& operator= (const Duelist&);
	~Duelist();

	void ChangeDeck(short, const char*, int, int);
	void ChangeDeck(short, const char*);
	void SetName(const char*);
	char* GetName() const;

};