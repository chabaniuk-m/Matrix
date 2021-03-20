#pragma once
#include <iostream>
class Drob
{
	int m_numerator;
	int m_denominator;
	
public:
	Drob(int numerator);
	Drob(int numerator, int denominator);

	int getNumerator() const;
	int getDenominator() const;

	void reduce();
	Drob operator* (const Drob& otherDrob) const;
	Drob operator/ (const Drob& otherDrob) const;
	Drob operator+ (const Drob& otherDrob) const;
	Drob operator- (const Drob& otherDrob) const;
	bool operator== (const Drob& otherDrob) const;
	bool operator!= (const Drob& otherDrob) const;
	Drob& operator= (const Drob& otherDrob);					//defined		
	Drob& operator+= (const Drob& otherDrob);
	Drob& operator-= (const Drob& otherDrob);
	Drob& operator*= (const Drob& otherDrob);
	Drob& operator/= (const Drob& otherDrob);

	friend std::ostream& operator<< (std::ostream& out, const Drob& drob);

private:
	int gcd(int a, int b) const;
	int lcd(int a, int b) const;
};