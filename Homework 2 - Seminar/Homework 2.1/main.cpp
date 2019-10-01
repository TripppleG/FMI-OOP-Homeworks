#include "ClubCollection.h"

int main()
{
	ClubCollection d;
	
	User pesho("pesho", 20, 3000, 2, 2,"Rock");
	std::cout << d.AddRockClub("33", 40, 50) << std::endl;
	std::cout << d.AddToClub(pesho, "33") << std::endl;
	return 0;
}