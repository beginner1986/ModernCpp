#include <iostream>
#include <numeric>

int main()
{
	int x, y;
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "y = ";
	std::cin >> y;

	// C++ 17 feature
	std::cout << "lcm(" << x << "," << y << ") = " << std::lcm(x, y) << std::endl;

	return 0;
}