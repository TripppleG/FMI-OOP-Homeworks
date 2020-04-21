#include "Deck.h"
#include <ctime>

void Deck::ShuffleCharArrays(char ranks[13][3], char suits[4][9])
{
	for (int i = 0; i < 13; i++)
	{
		int randomIndex = rand() % 13;
		char temp[3];
		strcpy_s(temp, ranks[i]);
		strcpy_s(ranks[i], ranks[randomIndex]);
		strcpy_s(ranks[randomIndex], temp);
	}

	for (int i = 0; i < 4; i++)
	{
		int randomIndex = rand() % 4;
		char temp[9];
		strcpy_s(temp, suits[i]);
		strcpy_s(suits[i], suits[randomIndex]);
		strcpy_s(suits[randomIndex], temp);
	}
}

void Deck::DeckShuffle()
{
	for (int i = 0; i < numberOfCards; i++)
	{
		int randomIndex = rand() % numberOfCards;
		Card temp = cards[i];
		cards[i] = cards[randomIndex];
		cards[randomIndex] = temp;
	}
}

void Deck::SetSeries(const char series[11])
{
	int length = strlen(series);
	int numberOfDashes = (10 - length) / 2;
	for (int i = 0; i < numberOfDashes; i++)
	{
		this->series[i] = '-';
	}
	this->series[numberOfDashes] = '\0';
	strcat_s(this->series, series);
	for (int i = numberOfDashes + length; i < 10; i++)
	{
		this->series[i] = '-';
	}
	this->series[10] = '\0';
}

void Deck::CopyFrom(const Deck& other)
{
	numberOfCards = other.numberOfCards;
	numberOfDrawedCards = other.numberOfDrawedCards;
	SetSeries(other.series);
	cards = new Card[numberOfCards];
	for (int i = 0; i < numberOfCards; i++)
	{
		cards[i] = other.cards[i];
	}
}

void Deck::Free()
{
	delete[]cards;
}

Deck::Deck()
{
	srand(time(NULL));
	numberOfCards = 52;
	numberOfDrawedCards = 0;
	SetSeries("Default");
	cards = new Card[52];

	char ranks[13][3] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	char suits[4][9] = { "Spades", "Diamonds", "Hearts", "Clubs" };
	
	for (int i = 0; i < 52; i++)
	{
		cards[i] = Card(ranks[i % 13], suits[i / 13], series, i + 1);
	}
	DeckShuffle();
}

Deck::Deck(int numberOfCards, const char series[11])
{
	this->numberOfCards = numberOfCards;
	numberOfDrawedCards = 0;
	SetSeries(series);

	srand(time(NULL));
	cards = new Card[numberOfCards];
	char ranks[13][3] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	char suits[4][9] = { "Spades", "Diamonds", "Hearts", "Clubs" };
	
	for (int i = 0; i < numberOfCards; i++)
	{
		if (i != 0 && i % 52 == 0)
		{
			ShuffleCharArrays(ranks, suits);
		}
		cards[i] = Card(ranks[i % 13], suits[(i / 13) % 4], series, i + 1);
	}
	DeckShuffle();
}

Deck::Deck(const Deck& other)
{
	CopyFrom(other);
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Deck::~Deck()
{
	Free();
}

const Card& Deck::Draw()
{
	Card temp = cards[numberOfCards - 1];
	for (int i = numberOfCards - 1 ; i > 0; i--)
	{
		cards[i] = cards[i - 1];
	}
	cards[0] = temp;
	numberOfDrawedCards++;
	if (numberOfDrawedCards == numberOfCards)
	{
		numberOfDrawedCards = 0;
	}
	return temp;
}

void Deck::Swap(int first, int second)
{
	if (first < numberOfCards || second < numberOfCards)
	{
		throw std::invalid_argument("Invalid Card Number(s)!");
	}
	first--;
	second--;
	Card temp = cards[first];
	cards[first] = cards[second];
	cards[second] = temp;
}

int Deck::SuitCount(const char* suit)
{
	if (strcmp(suit, "Clubs") && strcmp(suit, "Diamonds") && strcmp(suit, "Hearts") && strcmp(suit, "Spades"))
	{
		throw std::invalid_argument("Suit must be Clubs, Diamonds, Hearts or Spades!");
	}
	int counter = 0;
	for (int i = 0; i < numberOfCards; i++)
	{
		if (!strcmp(cards[i].suit, suit))
		{
			counter++;
		}
	}
	return counter;
}

int Deck::RankCount(const char* rank)
{
	if (strcmp(rank, "2") && strcmp(rank, "3") && strcmp(rank, "4") && strcmp(rank, "5") &&
		strcmp(rank, "6") && strcmp(rank, "7") && strcmp(rank, "8") && strcmp(rank, "9") &&
		strcmp(rank, "10") && strcmp(rank, "J") && strcmp(rank, "Q") && strcmp(rank, "K") && strcmp(rank, "A"))
	{
		throw std::invalid_argument("Suit must be 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K or A!");
	}
	int counter = 0;
	for (int i = numberOfDrawedCards; i < numberOfCards; i++)
	{
		if (!strcmp(cards[i].rank, rank))
		{
			counter++;
		}
	}
	return counter;
}

const char* Deck::GetSeries() const
{
	return series;
}

int Deck::GetNuberOfCards() const
{
	return numberOfCards;
}

int Deck::GetNumberOfDrawedCards() const
{
	return numberOfDrawedCards;
}

const Card& Deck::GetCardOnPos(int position)const
{
	return cards[position];
}

void Deck::PrintDeck() const
{
	for (int i = 0; i < numberOfCards; i++)
	{
		std::cout << cards[i].rank << " " << cards[i].suit << std::endl;
	}
}