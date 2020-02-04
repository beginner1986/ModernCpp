#include <iostream>

bool isPrime(const int x);

int main()
{
	int limit = 0;
	std::cout << "limit = ";
	std::cin >> limit;

	for (int i = limit - 1; i > 1; i--)
	{
		if (isPrime(i))
		{
			std::cout << "The greatest prime number smaller than " 
				<< limit << " is " << i << "." << std::endl;
			break;
		}
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