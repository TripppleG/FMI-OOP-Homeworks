#pragma once
#include <iostream>

class BooleanExpression
{
public:
	virtual int NumberOfVariables() = 0;
	virtual void Evaluate() = 0;
	virtual void Print() = 0;

	virtual bool IsTautology();
	virtual bool IsContradiction();
	virtual bool IsContingency();
	virtual ~BooleanExpression(){}
};