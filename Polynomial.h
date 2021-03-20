#pragma once
#include "Monomial.h"
#include <vector>
class Polynomial
{
	std::vector<Monomial> m_polinom;

public:
	Polynomial(int freeMember);
	Polynomial(const Polynomial& rhs);

	void push(Monomial mon);							//додоємо одночлен до поліному
	Drob value(int x) const;							//значення полінома в точці
	void simplify();									//звести подібні доданки (метод спочатку сортує)
	int getGreatestDegree();
	Drob getFreeMember();
	std::vector<Drob> getRoots() const;					//ГОЛОВНИЙ МЕТОД

	Polynomial operator+ (const Polynomial& pol) const;	//сортувати і спрощувати вихідний поліном після кожної операції
	Polynomial operator- (const Polynomial& pol) const;
	Polynomial operator* (const Polynomial& pol) const;	//працюватиме і з домноженням на число
	Polynomial operator/ (Polynomial& pol);	//поліноми після simplify()
	Polynomial& operator= (const Polynomial& pol);

	friend std::ostream& operator<< (std::ostream& out, const Polynomial& pol);

private:
	Polynomial() {}
	void sort();									//сортуємо від найбільшого до найменшого степеня
	bool isKSmaller(const Monomial* k, const Monomial* m) const;
};

