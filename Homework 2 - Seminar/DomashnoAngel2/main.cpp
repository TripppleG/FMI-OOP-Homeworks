#include "Statement.h"
#include "Operation.h"

int main()
{
	BooleanExpression* a = new Statement('a');
	BooleanExpression* b = new Statement('b');
	BooleanExpression* c = new Statement('c');

	BooleanExpression* p = new Operation(a, '^', b);
	BooleanExpression* q = new Operation(p, '>', c);

	BooleanExpression* r = new Operation(b, '>', c);
	BooleanExpression* s = new Operation(a, '>', r);

	BooleanExpression* f = new Operation(q, '=', s);
	std::cout << p->IsTautology();

	delete s;

	return 0;
}