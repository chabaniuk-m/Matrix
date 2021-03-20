#include "Drob.h"
#include <cassert>

Drob::Drob(int numerator, int denominator):
	m_numerator(numerator), m_denominator(denominator)
{
	assert(denominator != 0);
	if (m_denominator < 0)
	{
		if (m_denominator < 0)
		{
			m_numerator = fabs(m_numerator);
			m_denominator = fabs(m_denominator);
		}
		else
		{
			m_denominator = fabs(m_denominator);
			m_numerator *= -1;
		}
	}
}

Drob::Drob(int numerator):
	m_numerator(numerator), m_denominator(1)
{
}

int Drob::getNumerator() const
{
	return m_numerator;
}

int Drob::getDenominator() const
{
	return m_denominator;
}

void Drob::reduce()
{
	int GCD(fabs(gcd(m_numerator, m_denominator)));
	m_numerator /= GCD;
	m_denominator /= GCD;
}

Drob Drob::operator*(const Drob& otherDrob) const
{
	assert("Division by zero", otherDrob.m_numerator != 0);

	Drob multiplication(m_numerator * otherDrob.m_numerator, m_denominator * otherDrob.m_denominator);
	multiplication.reduce();

	return multiplication;
}

Drob Drob::operator/(const Drob& otherDrob) const
{
	Drob fraction(m_numerator * otherDrob.m_denominator, m_denominator * otherDrob.m_numerator);
	fraction.reduce();

	return fraction;
}

Drob Drob::operator-(const Drob& otherDrob) const
{
	int LCD = lcd(m_denominator, otherDrob.m_denominator);

	Drob difference(m_numerator * LCD / m_denominator - otherDrob.m_numerator * LCD / otherDrob.m_denominator, LCD);

	difference.reduce();

	return difference;
}

bool Drob::operator==(const Drob& otherDrob) const
{
	if (m_numerator == 0) return otherDrob.m_numerator == 0;

	Drob drob(*this);										//вимушений створювати копії дробів, щоб зберегти констаня
	drob.reduce();
	Drob theOtherDrob(otherDrob);
	theOtherDrob.reduce();

	return drob.m_numerator == theOtherDrob.m_numerator && drob.m_denominator == theOtherDrob.m_denominator;
}

bool Drob::operator!=(const Drob& otherDrob) const
{
	return !(*this == otherDrob);
}

Drob Drob::operator+(const Drob& otherDrob) const
{
	int LCD = fabs(lcd(m_denominator, otherDrob.m_denominator));

	Drob summary(m_numerator * LCD / m_denominator + otherDrob.m_numerator * LCD / otherDrob.m_denominator, LCD);

	summary.reduce();

	return summary;
}

Drob& Drob::operator=(const Drob& otherDrob)
{
	m_numerator = otherDrob.m_numerator;
	m_denominator = otherDrob.m_denominator;

	return *this;
}

Drob& Drob::operator+=(const Drob& otherDrob)
{
	*this = *this + otherDrob;

	return *this;
}

Drob& Drob::operator-=(const Drob& otherDrob)
{
	*this = *this - otherDrob;

	return *this;
}

Drob& Drob::operator*=(const Drob& otherDrob)
{
	*this = *this * otherDrob;

	return *this;
}

Drob& Drob::operator/=(const Drob& otherDrob)
{
	*this = *this / otherDrob;

	return *this;
}

int Drob::lcd(int a, int b) const
{
	return a * b / gcd(a, b);
}

int Drob::gcd(int a, int b) const
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

std::ostream& operator<< (std::ostream& out, const Drob& drob)
{
	out << drob.getNumerator();

	if (drob.getDenominator() != 1)
	{
		out << "/" << drob.getDenominator();
	}

	return out;
}