#include "Matrix.h"
#include <Windows.h>

void showRoots(std::vector<int> roots)
{
	std::cout << "Власні числа:\n";
	int number = 1;
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
	std::cout << pre_root << "\n";
}

int main()
{
	SetConsoleOutputCP(1251);

	Matrix matrix;

	char c;
	do
	{
		matrix.initialize();

		showRoots(matrix.getEigenValues());

		std::cout << "\nПродовжити(1) або вийти(0): ";
		std::cin >> c;
		std::cin.ignore();
		std::cout << "\n";
	}
	while (c != '0');

	std::cout << "Програма завершила своє виконання\n";
	std::cin.get();
}