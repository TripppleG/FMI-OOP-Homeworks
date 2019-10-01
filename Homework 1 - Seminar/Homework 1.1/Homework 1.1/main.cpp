#include <iostream>
#include "Date.h"

int main()
{
	Date d1(2, 5, 2000);
	Date d2(9, 5, 2000);
	std::cout << GetDifference(d1, d2);
	return 0;
}