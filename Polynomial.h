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
	void simplify();									//������ ����� ������� (����� �������� �����)
	int getGreatestDegree();
	Drob getFreeMember();
	std::vector<Drob> getRoots() const;					//�������� �����

	Polynomial operator+ (const Polynomial& pol) const;	//��������� � ���������� �������� ������ ���� ����� ��������
	Polynomial operator- (const Polynomial& pol) const;
	Polynomial operator* (const Polynomial& pol) const;	//����������� � � ����������� �� �����
	Polynomial operator/ (Polynomial& pol);	//������� ���� simplify()
	Polynomial& operator= (const Polynomial& pol);

	friend std::ostream& operator<< (std::ostream& out, const Polynomial& pol);

private:
	Polynomial() {}
	void sort();									//������� �� ���������� �� ���������� �������
	bool isKSmaller(const Monomial* k, const Monomial* m) const;
};

