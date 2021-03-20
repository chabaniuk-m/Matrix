#include "Polynomial.h"

void swap(Monomial* a, Monomial* b)
{
    Monomial t = *a;
    *a = *b;
    *b = t;
}
void Polynomial::sort()
{
    for (int i = 0; i < m_polinom.size() - 1; ++i)
    {
        for (int j = 0; j < m_polinom.size() - 1 - i; ++j)
        {
            if (isKSmaller(&m_polinom[j], &m_polinom[j + 1]))
            {
                swap(&m_polinom[j], &m_polinom[j + 1]);
            }
        }
    }
}

bool Polynomial::isKSmaller(const Monomial* k, const Monomial* m) const
{
    return k->getDegree() < m->getDegree();
}

std::ostream& operator<< (std::ostream& out, const Polynomial& pol)
{
    for (auto& k : pol.m_polinom)
    {
        out << k;
    }

    return out;
}

Polynomial::Polynomial(int freeMember)
{
    m_polinom.push_back(Monomial(Drob(freeMember)));
}

Polynomial::Polynomial(const Polynomial& rhs):
    m_polinom(rhs.m_polinom)
{
}

void Polynomial::push(Monomial mon)
{
    m_polinom.push_back(mon);
    sort();
}

Drob Polynomial::value(int x) const
{
    Drob sum = 0;
    for (auto& k : m_polinom)
    {
        sum += k.value(x);
    }

    return sum;
}

void Polynomial::simplify()
{
    sort();
    std::vector<Monomial> new_polinom;
    auto begin = m_polinom.begin();
    auto end = begin;
    Monomial* pmon = nullptr;

    for (; begin < m_polinom.end(); ++begin)
    {
        ++end;
        if (end == m_polinom.end())
        {
            --end;
            if (end->getCoefficient() != 0)
                new_polinom.push_back(*end);
            break;
        }
        if (begin->getDegree() == end->getDegree())
        {
            Monomial sum = *begin;

            do
            {
                sum += *end;
                ++end;
                if (end == m_polinom.end()) break;
            }
            while (begin->getDegree() == end->getDegree());

            if (sum.getCoefficient() != 0)
                new_polinom.push_back(sum);

            begin = end;
            --begin;
        }
        else
        {
            if (begin->getCoefficient() != 0)
                new_polinom.push_back(*begin);
        }
    }

    m_polinom = new_polinom;
}

int Polynomial::getGreatestDegree()
{
    simplify();
    return m_polinom[0].getDegree();
}

Drob Polynomial::getFreeMember()
{
    simplify();
    return (m_polinom[m_polinom.size() - 1].getDegree() == 0) ? m_polinom[m_polinom.size() - 1].getCoefficient() : Drob(0);
}

Polynomial Polynomial::operator+(const Polynomial& pol) const
{
    Polynomial sum;
    for (auto& k : m_polinom)
    {
        sum.m_polinom.push_back(k);
    }
    for (auto& k : pol.m_polinom)
    {
        sum.m_polinom.push_back(k);
    }

    sum.simplify();
    return sum;
}

Polynomial Polynomial::operator-(const Polynomial& pol) const
{
    Polynomial difference;
    for (auto& k : m_polinom)
    {
        difference.m_polinom.push_back(k);
    }
    for (auto& k : pol.m_polinom)
    {
        difference.m_polinom.push_back(Monomial(Drob(-1), 0) * k);
    }

    difference.simplify();
    return difference;
}

Polynomial Polynomial::operator*(const Polynomial& pol) const
{
    Polynomial mult;
    for (auto& k : m_polinom)
    {
        for (auto& m : pol.m_polinom)
        {
            mult.m_polinom.push_back(k * m);
        }
    }

    mult.simplify();
    return mult;
}

Polynomial Polynomial::operator/(Polynomial& pol)
{
    Polynomial fraction;

    pol.simplify();

    while (m_polinom[0].getDegree() >= pol.m_polinom[0].getDegree())
    {
        simplify();
    }

    std::cout << "division" << "\n";
}

Polynomial& Polynomial::operator=(const Polynomial& pol)
{
    m_polinom = pol.m_polinom;

    return *this;
}
