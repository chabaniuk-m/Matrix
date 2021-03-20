#include "Monomial.h"
#include <cassert>

Monomial::Monomial(Drob coefficient):
	m_coefficient(coefficient), m_degree(0)
{
}

Monomial::Monomial(Drob coefficient, int degree):
	m_coefficient(coefficient), m_degree(degree)
{
}

Drob Monomial::getCoefficient() const
{
	return m_coefficient;
}

int Monomial::getDegree() const
{
	return m_degree;
}

Monomial Monomial::operator+(const Monomial& otherMonomial) const
{
	assert(m_degree == otherMonomial.m_degree);

	return Monomial(m_coefficient + otherMonomial.m_coefficient, m_degree);
}

Monomial Monomial::operator-(const Monomial& otherMonomial) const
{
	assert(m_degree == otherMonomial.m_degree);

	return Monomial(m_coefficient - otherMonomial.m_coefficient, m_degree);
}

Monomial Monomial::operator*(const Monomial& otherMonomial) const
{
	return Monomial(m_coefficient * otherMonomial.m_coefficient, m_degree + otherMonomial.m_degree);
}

Monomial Monomial::operator/(const Monomial& otherMonomial) const
{
	assert("Division by zero" && otherMonomial.m_coefficient != 0);

	return Monomial(m_coefficient / otherMonomial.m_coefficient, m_degree - otherMonomial.m_degree);
}
