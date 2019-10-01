#include "Operation.h"
#include <math.h>

void Operation::Resize()
{
	bool** temp = new bool* [row * 2];
	for (int i = 0; i < row*2; i++)
	{
		temp[i] = new bool[column + 20];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			temp[i][j] = boolMatrix[i][j];
		}
		delete[] boolMatrix[i];
	}
	delete[] boolMatrix;
	row *= 2;
	column += 20;
	for (int i = 0; i < row; i++)
	{
		boolMatrix[i] = temp[i];
	}
	boolMatrix = temp;
}

Operation::Operation(BooleanExpression* leftStatement, char operation, BooleanExpression* rightStatement)
{
	boolMatrix = new bool* [row];
	for (int i = 0; i < row; i++)
	{
		boolMatrix[i] = new bool[column];
	}
	this->operation = operation;
	if (operation == '!')
	{
		this->leftStatement = nullptr;
	}
	else
	{
		this->leftStatement = leftStatement;
	}
	this->rightStatement = rightStatement;
}

Operation::~Operation()
{
	delete leftStatement;
	delete rightStatement;
	operation = '\0';
}

void Operation::Evaluate()
{
	int varCount = NumberOfVariables();
	if (row < pow(2, varCount))
	{
		bool** temp = new bool* [pow(2, varCount)];
		for (int i = 0; i < pow(2, varCount); i++)
		{
			temp[i] = new bool[varCount + 20];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				temp[i][j] = boolMatrix[i][j];
			}
			delete[] boolMatrix[i];
		}
		delete[] boolMatrix;
		row = pow(2, varCount);
		column = varCount;
		for (int i = 0; i < row; i++)
		{
			boolMatrix[i] = temp[i];
		}
		boolMatrix = temp;
	}
	for (int i = 0; i < pow(2, varCount); i++)
	{
		for (int j = 0; j < varCount; j++)
		{
			int k = pow(2, varCount - j);
			if (i % k < (k / 2))
			{
				boolMatrix[i][j] = false;
				std::cout << boolMatrix[i][j];
			}
			else
			{
				boolMatrix[i][j] = true;
				std::cout << boolMatrix[i][j];
			}
		}
		std::cout << std::endl;
	}
	leftStatement->Evaluate();
	rightStatement->Evaluate();

	if (operation == '!')
	{
		return;
	}
	else if (operation == '^')
	{
	}
	else if (operation == 'v')
	{
		return;
	}
	else if (operation == '+')
	{
		return;
	}
	else if (operation == '>')
	{
		return;
	}
	else if (operation == '=')
	{
		return;
	}
	else
	{
		throw "Invalid Operation!";
	}
	return;
}

int Operation::NumberOfVariables()
{
	if (!leftStatement)
	{
		return rightStatement->NumberOfVariables();
	}
	return leftStatement->NumberOfVariables() + rightStatement->NumberOfVariables();
}

bool Operation::IsTautology()
{
	Evaluate();
	//for (int i = 0; i < row; i++)
	//{
	//	if (!arr[i][column - 1])
	//	{
	//		return false;
	//	}
	//}
	return true;
}

bool Operation::IsContradiction()
{
	Evaluate();
	/*for (int i = 0; i < row; i++)
	{
		if (arr[i][column - 1])
		{
			return false;
		}
	}*/
	return true;
}

bool Operation::IsContingency()
{
	return true;// !IsTautology() && !IsContradiction();
}

void Operation::Print()
{
	std::cout << '(';
	leftStatement->Print();
	std::cout << operation;
	rightStatement->Print();
	std::cout << ')';
}
