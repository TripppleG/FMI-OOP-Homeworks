#include "BlackJack.h"

void BlackJack::PlayerDraw()
{
	Card card = deck.Draw();
	if (card.GetValue() == 11)
	{
		if (playerCurrentPoints > 10)
		{
			playerCurrentPoints += 1;
		}
		else
		{
			playerCurrentPoints += 11;
		}
	}
	else
	{
		playerCurrentPoints += card.GetValue();
	}
	std::cout << card.GetRank() << "(" << card.GetSuit() << ")" << " (Points: " << playerCurrentPoints << ")\n\n";
}

void BlackJack::DealerDraw()
{
	std::cout << "The dealer's draw: ";
	while (dealerCurrentPoints < 18)
	{
		Card card = deck.Draw();
		dealerCurrentPoints += card.GetValue();
		std::cout << card.GetRank() << "(" << card.GetSuit() << "), ";
	}
	std::cout << "(Points: " << dealerCurrentPoints << ")\n";
}

void BlackJack::GameStart(bool newGame)
{
	char name[MAX_NAME_SIZE];
	int age;
	playerCurrentPoints = 0;
	dealerCurrentPoints = 0;
	chanceToTwentyOne = 0;

	std::cout << "Enter your name: ";
	if (newGame)
	{
		std::cin.ignore();
	}
	std::cin.getline(name, MAX_NAME_SIZE);
	std::cout << "Enter your age: ";
	std::cin >> age;
	player = Player(name, age);
	int choice;
	do
	{
		std::cout << "Would you like to play with:\n1) Standard deck (52 card)\n2) Custom deck(you would have to enter the number of cards you want in it)\n";
		std::cin >> choice;
		if (choice == 1)
		{
			deck = Deck();
		}
		else if (choice == 2)
		{
			std::cout << "Enter the number of cards you would like to play with: ";
			int numberOfCards;
			std::cin >> numberOfCards;
			while (numberOfCards < 52)
			{
				std::cout << "You can't play with less than 52 cards! Choose the number of cards again: ";
				std::cin >> numberOfCards;
			}
			deck = Deck(numberOfCards);
		}
		else
		{
			std::cout << "Incorrect choice!\n";
		}
	} while (choice != 1 && choice != 2);

	std::cout << "\nHello, " << player.GetName() << "! Your game starts now!\n";
}

void BlackJack::SaveToFile(const char* fileName)
{
	char name[sizeof(Player)];
	std::fstream ioFile(fileName, std::fstream::in | std::fstream::out | std::fstream::ate);
	if (!ioFile)
	{
		throw std::runtime_error("Could not open file!");
	}
	while (!ioFile.eof())
	{
		ioFile.read(name, sizeof(Player));

		if (!strcmp(name, player.GetName()))
		{
			player.Write(ioFile);
			break;
		}
	}
	player.Write(ioFile);
}

double BlackJack::ChanceToTwentyOne(const Deck& deck)
{
	if (playerCurrentPoints < 10)
	{
		return 0;
	}
	int counter = 0;
	int pointsToTwentyOne = 21 - playerCurrentPoints;
	int numberOfUndrawedCards = deck.GetNuberOfCards() - deck.GetNumberOfDrawedCards();
	for (int i = 0; i < numberOfUndrawedCards; i++)
	{
		if (deck.GetCardOnPos(i).GetValue() == pointsToTwentyOne || (playerCurrentPoints == 20 && deck.GetCardOnPos(i).GetValue() == 11))
		{
			counter++;
		}
	}
	return (double)counter / numberOfUndrawedCards;
}

BlackJack::BlackJack()
{
	GameStart();
	PlayerDraw();
	short choice;
	bool newGame = false;
	do
	{
		if (!newGame)
		{
			std::cout << "Choose what you want to do:\n1) Draw a card\n2) Stand\n3) See your chance to hit exactly 21 points\n";
			std::cin >> choice;
		}
		else
		{
			newGame = false;
		}
		if (choice == 1)
		{
			bool gameEnd = false;
			PlayerDraw();
			if (playerCurrentPoints == 21)
			{
				std::cout << "Congratulations! You win!\n";
				playerWins++;
				gameEnd = true;
			}
			else if (playerCurrentPoints > 21)
			{
				std::cout << "You lose!\n";
				gameEnd = true;
			}
			if (gameEnd)
			{
				playerGamesPlayed++;
				playerWinCoef = (double)(playerWins / playerGamesPlayed);
				std::cout << "Would you like one more game? [y/n]\n";
				char charChoice;
				std::cin >> charChoice;
				newGame = true;

				while (charChoice != 'y' && charChoice != 'Y' && charChoice != 'n' && charChoice != 'N')
				{
					std::cout << "Invalid choice! Would you like one more game? [y/n]\n";
					std::cin >> charChoice;
				}
				if (charChoice == 'y' || charChoice == 'Y')
				{
					GameStart(true);
					choice = 1;
				}
				else
				{
					break;
				}
			}
		}
		else if (choice == 2)
		{
			DealerDraw();
			if (playerCurrentPoints >= dealerCurrentPoints || dealerCurrentPoints > 21)
			{
				std::cout << "Congratulations! You win!\n";
				playerWins++;
			}
			else
			{
				std::cout << "You lose!\n";
			}
			playerGamesPlayed++;
			playerWinCoef = (double)(playerWins / playerGamesPlayed);
			std::cout << "Would you like one more game? [y/n]\n";
			char charChoice;
			std::cin >> charChoice;

			while (charChoice != 'y' && charChoice != 'Y' && charChoice != 'n' && charChoice != 'N')
			{
				std::cout << "Invalid choice! Would you like one more game? [y/n]\n";
				std::cin >> charChoice;
			}
			if (charChoice == 'y' || charChoice == 'Y')
			{
				newGame = true;
				GameStart(true);
				choice = 1;
				continue;
			}
			else
			{
				break;
			}
		}
		else if (choice == 3)
		{
			std::cout << ChanceToTwentyOne(deck) << " (Points: " << playerCurrentPoints << ")\n";
		}
		else
		{
			std::cout << "Incorrect choice!\n";
		}
	} while (choice != 2);
	SaveToFile("Player.txt");
}
