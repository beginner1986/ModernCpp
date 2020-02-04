// print the GCD of two given numbers

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
	std::cout << "gcd(" << x << "," << y << ") = " << std::gcd(x, y) << std::endl;

	return 0;
}