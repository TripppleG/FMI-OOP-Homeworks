#include "Card.h"

int Card::NumberOfDigits(int number)const
{
	int k = 0;
	while (number != 0)
	{
		k++;
		number /= 10;
	}
	return k;
}

void Card::SetSuit(const char suit[9])
{
	strcpy_s(this->suit, suit);
}

void Card::SetRank(const char rank[3])
{
	strcpy_s(this->rank, rank);
}

void Card::SetSerialNumber(const char deckSeries[11], int cardNumber)
{
	int digitNumber = NumberOfDigits(cardNumber);
	strcpy_s(serialNumber, deckSeries); // Coping the deckSeries
	int indexOfDashes = (25 - digitNumber) / 2;  // The index of the last dash of the first series of dashes. Example: If
															    // cardNumber is 1, then the SN would be -Default-- --1-- (without the space)
																//					and here would be indexOfDashes: ^ 
	for (int i = 10; i < indexOfDashes; i++) // Adding the first set of dashes
	{
		serialNumber[i] = '-';
	}

	for (int i = indexOfDashes + digitNumber; i > indexOfDashes; i--) // Adding the Card Number
	{
		serialNumber[i - 1] = cardNumber % 10 + '0';
		cardNumber /= 10;
	}
	for (int i = digitNumber + indexOfDashes; i < 15 ; i++) // Adding the second set of dashes
	{
		serialNumber[i] = '-';
	}
	serialNumber[15] = '\0';
}

void Card::SetValue()
{
	if (!strcmp(rank, "10") || !strcmp(rank, "J") || !strcmp(rank, "Q") || !strcmp(rank, "K"))
	{
		value = 10;
	}
	else if (!strcmp(rank, "A"))
	{
		value = 11;
	}
	else
	{
		value = rank[0] - '0';
	}
}

Card::Card(const char rank[3], const char suit[9], const char deckSeries[11], int cardNumber)
{
	SetRank(rank);
	SetSuit(suit);
	SetSerialNumber(deckSeries, cardNumber);
	SetValue();
}

const char* Card::GetSuit() const
{
	return suit;
}

const char* Card::GetRank() const
{
	return rank;
}

unsigned short Card::GetValue()const
{
	return value;
}