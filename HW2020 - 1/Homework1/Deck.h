#pragma once
#include "Card.h"

class Deck
{
	Card* cards;
	char series[11];
	int numberOfCards;
	int numberOfDrawedCards;
	
	void ShuffleCharArrays(char ranks[13][3], char suits[4][9]);
	void DeckShuffle();
	void SetSeries(const char series[11]);

	void CopyFrom(const Deck& other);
	void Free();
public:
	Deck();
	Deck(int numberOfCards, const char series[11] = "--Custom--");
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();

	const Card& Draw();
	void Swap(int first, int second);
	int SuitCount(const char* suit);
	int RankCount(const char* rank);
	void PrintDeck()const;

	const char* GetSeries()const;
	int GetNuberOfCards()const;
	int GetNumberOfDrawedCards()const;
	const Card& GetCardOnPos(int position)const;
};