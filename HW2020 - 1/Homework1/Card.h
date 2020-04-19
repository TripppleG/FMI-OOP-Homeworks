#pragma once
#include <iostream>
#include <string.h>

class Card
{
private:
	friend class Deck;
	char suit[9];
	char rank[3];
	char serialNumber[16];
	unsigned short value;

	int NumberOfDigits(int number)const;

	void SetSuit(const char suit[9]);
	void SetRank(const char rank[3]);
	void SetSerialNumber(const char deckSeries[11], int cardNumber);
	void SetValue();

	Card() : suit(""), rank(""), serialNumber(""), value(0) {}
	Card(const char rank[3], const char suit[9], const char deckSeries[11], int cardNumber);
public:
	const char* GetSuit()const;
	const char* GetRank()const;
	unsigned short GetValue()const;
};