#include "BlackJack.h"
#include <iomanip>

void BlackJack::GameStart(bool newGame)
{
	char name[MAX_NAME_SIZE];
	int age;
	playerCurrentPoints = 0;
	dealerCurrentPoints = 0;
	chanceToTwentyOne = 0;

	if (newGame)
	{
		std::cout << std::endl;
	}

	std::ifstream inFile(FILE_NAME, std::ios::binary);
	if (!inFile)
	{
		inFile.open(FILE_NAME, std::ios::out | std::ios::trunc | std::ios::binary); // Creating a new file if it doesn't exist
	}
	int i = 1;
	if (inFile.peek() != std::ifstream::traits_type::eof()) // Checking if the file is empty
	{
		std::cout << "Choose a player or enter a new one:\n";
	}
	while(!inFile.eof())
	{
		Player temp;
		temp.Read(inFile);
		if (!inFile.eof())
		{
			std::cout << i++ << ") " << temp.name << std::endl;
		}
	}
	inFile.clear();
	inFile.seekg(inFile.beg);
	std::cout << "Enter your name: ";
	if (newGame)
	{
		std::cin.ignore();
	}
	std::cin.getline(name, MAX_NAME_SIZE);
	bool newPlayer = true;

	while (!inFile.eof())
	{
		Player temp;
		temp.Read(inFile);
		if (!strcmp(temp.name, name))
		{
			player = temp;
			newPlayer = false;
			break;
		}
	}
	if (newPlayer)
	{
		std::cout << "Enter your age: ";
		std::cin >> age;
		player = Player(name, age);
	}
	short choice;
	std::cout << std::endl;
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

void BlackJack::SaveToFile(const char* fileName)
{
	std::fstream ioFile(fileName, std::ios::in | std::ios::out | std::ios::binary);
	if (!ioFile)
	{
		throw std::runtime_error("File couldn't be opened!");
	}
	while (!ioFile.eof())
	{
		int getPos = ioFile.tellg();
		Player temp;
		temp.Read(ioFile);
		if (!strcmp(temp.name, player.name))
		{
			ioFile.seekp(getPos);
			break;
		}
	}
	ioFile.clear();
	player.Write(ioFile);
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
			PlayerDraw();
			bool gameEnd = false;
			if (playerCurrentPoints == 21)
			{
				std::cout << "Congratulations! You win!\n";
				player.wins++;
				gameEnd = true;
			}
			else if (playerCurrentPoints > 21)
			{
				std::cout << "You lose!\n";
				gameEnd = true;
			}
			if (gameEnd)
			{
				player.playedGames++;
				player.winCoef = (double)player.wins / (double)player.playedGames;
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
					SaveToFile(FILE_NAME);
					GameStart(true);
					choice = 1;
				}
				else
				{
					SaveToFile(FILE_NAME);
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
				player.wins++;
			}
			else
			{
				std::cout << "You lose!\n";
			}
			player.playedGames++;
			player.winCoef = (double)player.wins / (double)player.playedGames;
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
				SaveToFile(FILE_NAME);
				GameStart(true);
				choice = 1;
			}
			else
			{
				SaveToFile(FILE_NAME);
				break;
			}
		}
		else if (choice == 3)
		{
			std::cout << "Chance to hit 21: " << std::setprecision(2) << std::fixed << ChanceToTwentyOne(deck) * 100 << "% (Points: " << playerCurrentPoints << ")\n\n";
		}
		else
		{
			std::cout << "Incorrect choice!\n";
		}
	} while (true);
	std::cout << "All changes are saved successfully in the file!\n";
}