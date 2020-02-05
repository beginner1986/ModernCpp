// print the prime factors of the given number

#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> primeFactors(int x);

int main()
{
	int num;
	std::cout << "number = ";
	std::cin >> num;

	std::vector<int> factors = primeFactors(num);

	std::copy(std::begin(factors), std::end(factors), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}

std::vector<int> primeFactors(int x)
{
	std::vector<int> result;

	if (x % 2 == 0)
	{
		result.push_back(2);
		x /= 2;
	}

	for (int i = 3; i < sqrt(x); i += 2)
	{
		while (x % i == 0)
		{
			result.push_back(i);
			x /= i;
		}

		if (x > 2)
			result.push_back(x);
	}

	return result;
}