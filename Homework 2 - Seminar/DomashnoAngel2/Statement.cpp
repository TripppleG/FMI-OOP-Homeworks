#include "Statement.h"

Statement::Statement(char variable)
{
	this->variable = variable;
}

bool Statement::Evaluate()
{
	return true;
}

void Statement::Print()
{
	std::cout << variable;
}

Statement::~Statement()
{
	variable = '\0';
}
