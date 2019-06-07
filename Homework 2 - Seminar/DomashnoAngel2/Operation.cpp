#include "Operation.h"

Operation::Operation(BooleanExpression* leftStatement, char operation, BooleanExpression* rightStatement)
{
	leftStatement->firstCase = false;
	leftStatement->secondCase = false;
	leftStatement->thirdCase = true;
	leftStatement->fourthCase = true;

	rightStatement->firstCase = false;
	rightStatement->secondCase = true;
	rightStatement->thirdCase = false;
	rightStatement->fourthCase = true;

	this->leftStatement = leftStatement;
	this->operation = operation;
	this->rightStatement = rightStatement;
	Evaluate();
}

Operation::Operation(char operation, BooleanExpression* leftStatement)
{
	rightStatement->firstCase = false;
	rightStatement->secondCase = true;
	rightStatement->thirdCase = false;
	rightStatement->fourthCase = true;

	this->operation = operation;
	this->leftStatement = leftStatement;
	Evaluate();
	
}

Operation::~Operation()
{
	delete leftStatement;
	delete rightStatement;
	operation = '\0';
}


bool Operation::Evaluate()
{
	leftStatement->Evaluate();
	rightStatement->Evaluate();
	if (operation == '!')
	{
		resultFirstCase = !leftStatement->firstCase;
		resultSecondCase = !leftStatement->secondCase;
		resultThirdCase = !leftStatement->thirdCase;
		resultFourthCase = !leftStatement->fourthCase;
	}
	if (operation == '^')
	{
		resultFirstCase = leftStatement->firstCase && rightStatement->firstCase;
		resultSecondCase = leftStatement->secondCase && rightStatement->secondCase;
		resultThirdCase = leftStatement->thirdCase && rightStatement->thirdCase;
		resultFourthCase = leftStatement->fourthCase && rightStatement->fourthCase;
	}
	else if (operation == 'v')
	{
		resultFirstCase = leftStatement->firstCase || rightStatement->firstCase;
		resultSecondCase = leftStatement->secondCase || rightStatement->secondCase;
		resultThirdCase = leftStatement->thirdCase || rightStatement->thirdCase;
		resultFourthCase = leftStatement->fourthCase || rightStatement->fourthCase;
	}
	else if (operation == '+')
	{
		resultFirstCase = leftStatement->firstCase ^ rightStatement->firstCase;
		resultSecondCase = leftStatement->secondCase ^ rightStatement->secondCase;
		resultThirdCase = leftStatement->thirdCase ^ rightStatement->thirdCase;
		resultFourthCase = leftStatement->fourthCase ^ rightStatement->fourthCase;
	}
	else if (operation == '>')
	{
		resultFirstCase = !leftStatement->firstCase || rightStatement->firstCase;
		resultSecondCase = !leftStatement->secondCase || rightStatement->secondCase;
		resultThirdCase = !leftStatement->thirdCase || rightStatement->thirdCase;
		resultFourthCase = !leftStatement->fourthCase || rightStatement->fourthCase;
	}
	else if (operation == '=')
	{
		resultFirstCase = !(leftStatement->firstCase ^ rightStatement->firstCase);
		resultSecondCase = !(leftStatement->secondCase ^ rightStatement->secondCase);
		resultThirdCase = !(leftStatement->thirdCase ^ rightStatement->thirdCase);
		resultFourthCase = !(leftStatement->fourthCase ^ rightStatement->fourthCase);
	}
	else
	{
		throw "Invalid Operation!";
	}
	return true;
}

bool Operation::IsTautology()
{
	return resultFirstCase && resultSecondCase && resultThirdCase && resultFourthCase;
}

bool Operation::IsContradiction()
{
	return !resultFirstCase && !resultSecondCase && !resultThirdCase && !resultFourthCase;
}

bool Operation::IsContingency()
{
	return !IsTautology() && !IsContradiction();
}

void Operation::Print()
{
	std::cout << '(';
	leftStatement->Print();
	std::cout << operation;
	rightStatement->Print();
	std::cout << ')';
}
