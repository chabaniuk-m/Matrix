#include "Polynomial.h"

bool test()
{
	Polynomial p(1);
	Polynomial p1(5);

	Monomial a(1, 3),
		b(1, 2),
		c(-1, 1),
		e(Drob(5, 6), 3),
		f(Drob(0), 7),
		g(Drob(-3, 11), 1),
		h(Drob(-5, 2), 0),
		d(5, 2);

	
	p.push(c);

	p1.push(c);

	std::cout << p << "\n";
	std::cout << p1 << "\n";

	p / p1;

	std::cout << (p).getGreatestDegree() << "\n";

	return false;
}

int main()
{
	test();
}