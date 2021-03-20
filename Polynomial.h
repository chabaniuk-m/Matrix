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
	void value(int x) const;							//�������� ������� � �����
	void simplify();									//������ ����� ������� (����� �������� �����)
	void getGreatestDegree() const;
	std::vector<Drob> getRoots() const;					//�������� �����

	Polynomial operator+ (const Polynomial& pol) const;	//��������� �������� ������ ���� ����� ��������
	Polynomial operator- (const Polynomial& pol) const;
	Polynomial operator* (const Polynomial& pol) const;
	Polynomial operator/ (const Polynomial& pol) const;


private:
	void sort() const;									//������� �� ���������� �� ���������� �������

};

