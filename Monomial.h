#pragma once
#include "Drob.h"
class Monomial
{
	Drob m_coefficient;
	int m_degree;

public:
	Monomial(Drob coefficient);
	Monomial(Drob coefficient, int degree);

	Drob getCoefficient() const;
	int getDegree() const;
	Drob value(int x) const;

	Monomial operator+ (const Monomial& otherMonomial) const;
	Monomial operator- (const Monomial& otherMonomial) const;
	Monomial operator* (const Monomial& otherMonomial) const;
	Monomial operator/ (const Monomial& otherMonomial) const;
	bool operator== (const Monomial& otherMonomial) const;
	bool operator!= (const Monomial& otherMonomial) const;
	Monomial& operator= (const Monomial& otherMonomial);
	Monomial& operator+= (const Monomial& otherMonomial);
	Monomial& operator-= (const Monomial& otherMonomial);
	Monomial& operator*= (const Monomial& otherMonomial);
	Monomial& operator/= (const Monomial& otherMonomial);


	friend std::ostream& operator<< (std::ostream& out, const Monomial& monomial);

};

