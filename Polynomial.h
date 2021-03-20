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
	void value(int x) const;							//значення полінома в точці
	void simplify();									//звести подібні доданки (метод спочатку сортує)
	void getGreatestDegree() const;
	std::vector<Drob> getRoots() const;					//ГОЛОВНИЙ МЕТОД

	Polynomial operator+ (const Polynomial& pol) const;	//сортувати вихідний поліном після кожної операції
	Polynomial operator- (const Polynomial& pol) const;
	Polynomial operator* (const Polynomial& pol) const;
	Polynomial operator/ (const Polynomial& pol) const;


private:
	void sort() const;									//сортуємо від найбільшого до найменшого степеня

};

