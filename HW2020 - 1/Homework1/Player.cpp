#include "Player.h"

void Player::SetName(const char name[MAX_NAME_SIZE])
{
	int length = strlen(name);
	if (length == 0)
	{
		throw std::invalid_argument("Name must not be empty!");
	}
	int spaceIndex = 0;
	for (int i = 0; i < length; i++)
	{
		if ((tolower(name[i]) < 'a' || tolower(name[i]) > 'z') && name[i] != ' ')
		{
			throw std::invalid_argument("Name can't contain non-letter charachters!");
		}
		if (name[i] == ' ')
		{
			if (spaceIndex != 0)
			{
				throw std::invalid_argument("Name must be in exactly two words!");
			}
			spaceIndex = i;
		}
	}
	if (name[0] < 'A' || name[0] > 'Z' || name[spaceIndex + 1] < 'A' || name[spaceIndex + 1] > 'Z')
	{
		if (spaceIndex == 0)
		{
			throw std::invalid_argument("Name must be in exactly two words!");
		}
		throw std::invalid_argument("Names must start with uppercase letter!");
	}
	strcpy_s(this->name, name);
}

void Player::SetAge(unsigned age)
{
	if (age < 18)
	{
		throw std::invalid_argument("Player can't be underaged!");
	}
	if (age > 90)
	{
		throw std::invalid_argument("Player can't be over 90!");
	}
	this->age = age;
}

Player::Player(const char name[MAX_NAME_SIZE], int age)
{
	SetName(name);
	SetAge(age);
	wins = 0;
	winCoef = 0;
	playedGames = 0;
}

std::ostream& operator<<(std::ostream& is, Player p)
{
	return is << p.name << ' ' << p.age << ' ' << p.wins << ' ' << p.winCoef << std::endl;
}

std::istream& operator>>(std::istream& is, Player p)
{
	return (is >> p.age >> p.wins >> p.winCoef).getline(p.name, MAX_NAME_SIZE);
}

const char* Player::GetName() const
{
	return name;
}

unsigned Player::GetAge() const
{
	return age;
}

unsigned Player::GetWins() const
{
	return wins;
}

unsigned Player::GetPlayedGames() const
{
	return playedGames;
}

double Player::GetWinCoef() const
{
	return winCoef;
}

void Player::Write(std::ostream& os)
{
	os.write((const char*)this, sizeof(Player));
}

void Player::Read(std::istream& is)
{
	is.read((char*)this, sizeof(Player));
}