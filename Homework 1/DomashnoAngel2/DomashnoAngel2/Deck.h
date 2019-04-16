#pragma once
#include "Cards.h"

class Deck
{
private:
	Card cardsInDeck[40];
public:
	Deck();
	Deck(const char*);

	void ChangeCard(short, const char*, int, int);
	void ChangeCard(short, const char*);
	int NumberOfMonsterCards() const;
	int NumberOfMagicCards() const;
	void SaveDeckToFile(std::ofstream& file) const;
};