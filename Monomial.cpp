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

Drob Monomial::value(int x) const
{
	Drob a(m_coefficient * static_cast<int>(pow(x, m_degree)));
	a.reduce();

	return a;
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

bool Monomial::operator==(const Monomial& otherMonomial) const
{
	return m_coefficient == otherMonomial.m_coefficient && m_degree == otherMonomial.m_degree;
}

bool Monomial::operator!=(const Monomial& otherMonomial) const
{
	return !(*this == otherMonomial);
}

Monomial& Monomial::operator=(const Monomial& otherMonomial)
{
	m_coefficient = otherMonomial.m_coefficient;
	m_degree = otherMonomial.m_degree;

	return *this;
}

Monomial& Monomial::operator+=(const Monomial& otherMonomial)
{
	*this = *this + otherMonomial;

	return *this;
}

Monomial& Monomial::operator-=(const Monomial& otherMonomial)
{
	*this = *this - otherMonomial;

	return *this;
}

Monomial& Monomial::operator*=(const Monomial& otherMonomial)
{
	*this = *this * otherMonomial;

	return *this;
}

Monomial& Monomial::operator/=(const Monomial& otherMonomial)
{
	*this = *this / otherMonomial;

	return *this;
}

std::ostream& operator<< (std::ostream& out, const Monomial& monomial)
{
	if (monomial.m_coefficient.isNegative())
		out << "- " << (monomial.m_coefficient * -1);
	else
		out << "+ " << monomial.m_coefficient;

	if (monomial.m_degree != 0 && monomial.m_coefficient != 0)
	{
		out << "l";
		if (monomial.m_degree != 1)
		{
			out << "^";
			if (monomial.m_degree < 0)
				out << "(" << monomial.m_degree << ") ";
			else
				out << monomial.m_degree << " ";
		}
		else
			out << " ";
	}
	else
		out << " ";

	return out;
}