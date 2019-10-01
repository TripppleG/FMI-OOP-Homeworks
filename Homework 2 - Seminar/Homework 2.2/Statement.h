#pragma once
#include "BooleanExpression.h"

class Statement : public BooleanExpression
{
private:
	char variable;
	char foundVariables[20];
	
public:
	Statement(char);
	int NumberOfVariables();
	void Evaluate();
	void Print();
	~Statement();
};