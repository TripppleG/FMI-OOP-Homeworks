#include "Statement.h"
#include "Operation.h"

int main()
{
	BooleanExpression* a = new Statement('a');
	BooleanExpression* b = new Statement('b');
	BooleanExpression* c = new Statement('c');

	BooleanExpression* and1 = new Operation(a, '^', b);
	BooleanExpression* left = new Operation(and1, '>', c);

	BooleanExpression* r = new Operation(b, '>', c);
	BooleanExpression* right = new Operation(a, '>', r);

	BooleanExpression* final = new Operation(left, '^', right);
	//std::cout << final->NumberOfVariables() << std::endl;
	final->Evaluate();

	//delete final;

	return 0;
}