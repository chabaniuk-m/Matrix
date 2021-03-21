#include "Matrix.h"
#include <Windows.h>

void showRoots(std::vector<int> roots)
{
	std::cout << "Власні числа:\n";
	int number = 0;
	int pre_root = INT_MAX;
	for (auto& k : roots)
	{
		if (pre_root == INT_MAX)
		{
			std::cout << "l" << number++ << " = ";
			pre_root = k;
		}
		else if (k == pre_root)
		{
			std::cout << "l" << number++ << " = ";
		}
		else
		{
			std::cout << pre_root << "\n";
			std::cout << "l" << number++ << " = ";
			pre_root = k;
		}
	}
	std::cout << pre_root;
}

int main()
{
	SetConsoleOutputCP(1251);
	Matrix matrix;
	matrix.initialize();
	showRoots(matrix.getEigenValues());

	return 0;
}