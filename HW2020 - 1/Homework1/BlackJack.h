#pragma once
#include "Player.h"
#include "Deck.h"

const char FILE_NAME[] = "PlayersInfo.bin";

class BlackJack
{
	Player player;
	Deck deck;
	double chanceToTwentyOne;
	unsigned short playerCurrentPoints;
	unsigned short dealerCurrentPoints;

	void GameStart(bool newGame = false);
	void PlayerDraw();
	void DealerDraw();
	double ChanceToTwentyOne(const Deck& deck);
	void SaveToFile(const char* fileName);
public:
	BlackJack();
};