#pragma once
#include "Player.h"
#include "Deck.h"
#include <fstream>

class BlackJack
{
	Player player;
	Deck deck;
	double chanceToTwentyOne;
	unsigned short playerCurrentPoints;
	unsigned short dealerCurrentPoints;
	unsigned playerWins;
	unsigned playerGamesPlayed;
	double playerWinCoef; // TODO: Add to the constructor

	void PlayerDraw();
	void DealerDraw();
	void GameStart(bool newGame = false);
	void LoadFromFile(const char* fileName);
	double ChanceToTwentyOne(const Deck& deck);
public:
	BlackJack();
	unsigned wins()const { return playerWins; }
	unsigned games()const { return playerGamesPlayed; }
	unsigned coef()const { return playerWinCoef; }
	void SaveToFile(const char* fileName);

};