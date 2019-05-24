#include "Club.h"

Club::Club(){}

Club::Club(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	if (len == 0)
	{
		this->name[0] = '\0';
		throw "Invalid name!";
	}
	strcpy_s(this->name, len + 1, name);
}
