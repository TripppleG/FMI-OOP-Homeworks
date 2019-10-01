#pragma once
#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
private:
	BooleanExpression* leftStatement;
	char operation;
	BooleanExpression* rightStatement;
	void Resize();
	bool** boolMatrix;
	int row = 2;
	int column = 1;
public:
	Operation(BooleanExpression*, char, BooleanExpression*);
	Operation(const Operation&) = delete;
	Operation& operator=(const Operation&) = delete;
	~Operation();

	int NumberOfVariables();
	bool IsContradiction();
	bool IsContingency();
	bool IsTautology();
	void Evaluate();
	void Print();
};