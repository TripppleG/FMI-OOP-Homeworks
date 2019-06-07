#pragma once
#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
private:
	char operation;
	BooleanExpression* leftStatement;
	BooleanExpression* rightStatement;
	bool resultFirstCase = false;
	bool resultSecondCase = false;
	bool resultThirdCase = true;
	bool resultFourthCase = true;
	int variableCount = 0;
public:
	Operation(BooleanExpression*, char, BooleanExpression*);
	Operation(char, BooleanExpression*);
	~Operation();

	bool IsContradiction();
	bool IsContingency();
	bool IsTautology();
	bool Evaluate();
	void Print();
};