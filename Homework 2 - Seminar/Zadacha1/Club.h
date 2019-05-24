#pragma once
#include <string.h>

class Club
{
protected:
	char* name;
public:
	Club();
	Club(const char*);
	virtual Club* Clone() = 0;
	virtual ~Club() {};
};