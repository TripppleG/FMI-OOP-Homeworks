#pragma once
#include "BooleanExpression.h"

class Statement : public BooleanExpression
{
private:
	char variable;
public:
	Statement(char);
	bool Evaluate();
	void Print();
	~Statement();
};