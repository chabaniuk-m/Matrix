#pragma once
#include "Polynomial.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Matrix
{
	std::vector<std::vector<Polynomial>> m_matrix;

public:
	Matrix() {}

	void initialize();
	void show() const;

	auto getEigenValues()->std::vector<int>;
	auto getDeterminat()->Polynomial;

private:
	Matrix(const Matrix& matrix, size_t skipped_row, size_t skipped_column);		//алгебраїчне доповнення, don't forget coeff (-1)^(i+j)
	auto addLambda() -> void;
};

