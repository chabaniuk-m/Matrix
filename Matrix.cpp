#include "Matrix.h"

void Matrix::initialize()
{
	m_matrix.clear();
	std::cout << "Квадратна матриця:\n";
	std::string str;
	std::getline(std::cin, str);
	std::stringstream ss(str);
	std::vector<Polynomial> row;
	int a;
	while (!ss.eof())
	{
		ss >> a;
		row.push_back(a);
	}
	m_matrix.push_back(row);
	size_t N = row.size();
	for (size_t i = 1; i < N; ++i)
	{
		std::getline(std::cin, str);
		std::stringstream ss(str);
		size_t counter = 0;
		while (!ss.eof())
		{
			++counter;
			if (counter > N)
			{
				std::cout << "Кількість стовпців не відповідає першому рядку. Спробуйте ще раз\n\n";
				initialize();
				return;
			}
			ss >> a;
			row[counter - 1] = a;
		}
		if (counter < N)
		{
			std::cout << "Кількість стовпців не відповідає першому рядку. Спробуйте ще раз\n\n";
			initialize();
			return;
		}
		else
		{
			m_matrix.push_back(row);
		}
	}
}

void Matrix::show() const
{
	for (auto& k : m_matrix)
	{
		for (auto& m : k)
		{
			std::cout << std::setw(8) << m;
		}
		std::cout << "\n";
	}
}

auto Matrix::getEigenValues() -> std::vector<int>
{
	Matrix temp(*this, 99, 99);
	temp.addLambda();

	return temp.getDeterminat().getRoots();
}

auto Matrix::getDeterminat() -> Polynomial
{
	if (m_matrix.size() == 2)
	{
		return (m_matrix[0][0] * m_matrix[1][1]) - (m_matrix[0][1] * m_matrix[1][0]);
	}
	else
	{
		//розкладаємо за першим рядком
		Polynomial pol(0);

		for (size_t i = 0; i < m_matrix.size(); ++i)
		{
			//сума алгебраїчних доповнень помножених на відповідні елементи 1-го рядка
			Matrix algebraicComplement(*this, 0, i);
			pol += Polynomial(static_cast<int>(pow(-1, 0 + i))) * m_matrix[0][i] * algebraicComplement.getDeterminat();
		}

		return pol;
	}
}

auto Matrix::addLambda() -> void
{
	Monomial l(1, 1);
	Polynomial pol(0);
	pol.push(l);

	for (size_t i = 0; i < m_matrix.size(); i++)
	{
		m_matrix[i][i] -= pol;
	}
}

Matrix::Matrix(const Matrix& matrix, size_t skipped_row, size_t skipped_column)
{
	const size_t N = matrix.m_matrix.size();
	for (size_t i = 0; i < N; ++i)
	{
		if (i == skipped_row) continue;
		std::vector<Polynomial> v;

		for (size_t j = 0; j < N; j++)
		{
			if (j == skipped_column) continue;
			else
			{
				v.push_back(matrix.m_matrix[i][j]);
			}
		}

		m_matrix.push_back(v);
	}
}
