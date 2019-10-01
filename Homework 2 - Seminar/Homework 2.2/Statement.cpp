#include "Statement.h"

Statement::Statement(char variable)
{
	this->variable = variable;
}

int Statement::NumberOfVariables()
{
	for (int i = 0; i < 20; i++)
	{
		if (variable == foundVariables[i])
		{
			return 0;
		}
		if (foundVariables[i] <'a' || foundVariables[i] > 'z')
		{
			foundVariables[i] = variable;
			return 1;
		}
	}
}

void Statement::Evaluate()
{
	
}

void Statement::Print()
{
	std::cout << variable;
}

Statement::~Statement()
{
	variable = '\0';
}