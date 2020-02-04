#include <iostream>

bool isPrime(const int x);

int main()
{
	int limit;
	std::cout << "limit = ";
	std::cin >> limit;

	std::cout << std::endl << "Results: " << std::endl;

	for (int i = 2; i < limit - 6; i++)
	{
		if (isPrime(i) && isPrime(i + 6))
			std::cout << i << " - " << (i + 6) << std::endl;
	}

	return 0;
}

bool isPrime(const int x)
{
	if (x < 2)
		return false;
	else if (x == 2)
		return true;
	else if(x % 2 == 0 || x % 3 == 0)
	{
		return false;
	}
	else
	{
		for (int i = 5; i * i < x; i += 6)
		{
			if (x % i == 0 || x % (i + 2) == 0)
				return false;
		}
	}

	return true;
}