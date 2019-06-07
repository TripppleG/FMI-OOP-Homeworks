#pragma once
#include <iostream>

class BooleanExpression
{
public:
	bool firstCase;
	bool secondCase;
	bool thirdCase;
	bool fourthCase;
	virtual bool Evaluate() = 0;
	virtual void Print() = 0;
	virtual bool IsContradiction();
	virtual bool IsContingency();
	virtual bool IsTautology();
	//virtual bool IsContradiction() = 0;
	//virtual bool IsContingency() = 0;
	virtual ~BooleanExpression() {}
};