#pragma once
#include "Monomial.h"
#include <vector>
class Polynomial
{
	std::vector<Monomial> m_polinom;

public:
	Polynomial(int freeMember);
	Polynomial(const Polynomial& rhs);

	void push(Monomial mon);							//������ �������� �� �������
	Drob value(int x) const;							//�������� ������� � �����
	bool empty() const;
	void simplify();									//������ ����� ������� (����� �������� �����)
	int getLeastDegree();
	int getGreatestDegree();
	Drob getFreeMember();
	std::vector<Drob> getRoots();					//�������� ����� - ��������� ��� �����

	Polynomial operator+ (const Polynomial& pol) const;	//��������� � ���������� �������� ������ ���� ����� ��������
	Polynomial operator- (const Polynomial& pol) const;
	Polynomial operator* (const Polynomial& pol) const;	//����������� � � ����������� �� �����
	Polynomial operator/ (Polynomial& pol);	//������� ���� simplify()
	Polynomial& operator= (const Polynomial& pol);
	Polynomial& operator+= (const Polynomial& pol);
	Polynomial& operator-= (const Polynomial& pol);
	Polynomial& operator*= (const Polynomial& pol);
	Polynomial& operator/= (Polynomial& pol);


	friend std::ostream& operator<< (std::ostream& out, const Polynomial& pol);

private:
	Polynomial() {}
	Polynomial(const Monomial mon) : m_polinom{ mon }{}
	void sort();									//������� �� ���������� �� ���������� �������
	bool isKSmaller(const Monomial* k, const Monomial* m) const;
	std::vector<int> getAllIntegerDivisors(int n);
};

