#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < 40; ++i)
	{
		Deck::cardsInDeck[i].SetName("Token");
		Deck::cardsInDeck[i].SetAttPts(0);
		Deck::cardsInDeck[i].SetDefPts(0);
		Deck::cardsInDeck[i].MakeItMonster(true);
	}
}
Deck::Deck(const char* fileName)
{
	std::ifstream file(fileName);
	if (!file.good())
	{
		std::cout << "File doesnt exist!" << std::endl;
		for (int i = 0; i < 40; ++i)
		{
			Deck::cardsInDeck[i].SetName("Token");
			Deck::cardsInDeck[i].SetAttPts(0);
			Deck::cardsInDeck[i].SetDefPts(0);
			Deck::cardsInDeck[i].MakeItMonster(true);
		}
	}
}

void Deck::ChangeCard(short cardNumber, const char* name, int attackPoints, int defencePoints)
{
	if (cardNumber > 40 || cardNumber < 1)
	{
		std::cout << "Invalid card!";
		return;
	}
	cardsInDeck[cardNumber - 1].SetName(name);
	cardsInDeck[cardNumber - 1].MakeItMonster(true);
	cardsInDeck[cardNumber - 1].SetAttPts(attackPoints);
	cardsInDeck[cardNumber - 1].SetDefPts(defencePoints);
}

void Deck::ChangeCard(short cardNumber, const char* name)
{
	if (cardNumber > 40 || cardNumber < 1)
	{
		std::cout << "Invalid card!";
		return;
	}
	cardsInDeck[cardNumber - 1].SetName(name);
	cardsInDeck[cardNumber - 1].MakeItMonster(false);
}

int Deck::NumberOfMonsterCards() const
{
	int counter = 0;
	for (int i = 0; i < 40; ++i)
	{
		if (cardsInDeck[i].IsItMonster())
		{
			counter++;
		}
	}
	return counter;
}

int Deck::NumberOfMagicCards() const
{
	int counter = 0;
	for (int i = 0; i < 40; ++i)
	{
		if (!cardsInDeck[i].IsItMonster())
		{
			counter++;
		}
	}
	return counter;
}

void Deck::SaveDeckToFile(std::ofstream& file) const
{
	file.open("Deck.bat", std::ios::binary);
	if (!file)
	{
		std::cout << "File not opened";
		return;
	}
	file.write((const char*)cardsInDeck, sizeof(Deck));
	file.close();
}