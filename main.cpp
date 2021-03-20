#include "Polynomial.h"
#include <cassert>

bool test()
{
	Polynomial a(6);
	Polynomial b(3);
	Polynomial c(-1);
	Polynomial d(6);
	Polynomial e(0);


	a.push(Monomial(-1, 1));
	b.push(Monomial(1, 1));
	c.push(Monomial(1, 1));
	d.push(Monomial(Drob(1), 1));
	e.push(Monomial(1, 4));

	Polynomial divided = a * b * c * d * e;

	std::cout << divided << "\n";

	std::vector<Drob> v{ divided.getRoots() };

	for (auto& k : v)
	{
		std::cout << k << " ";
	}

	return false;
}

int main()
{
	test();
}