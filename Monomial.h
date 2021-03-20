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

	Monomial operator+ (const Monomial& otherMonomial) const;
	Monomial operator- (const Monomial& otherMonomial) const;
	Monomial operator* (const Monomial& otherMonomial) const;
	Monomial operator/ (const Monomial& otherMonomial) const;

};

