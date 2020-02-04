#include <iostream>

int sumProperDivisors(const int num);
void printAbundant(const int limit);

int main()
{
	int limit;
	std::cout << "limit = ";
	std::cin >> limit;

	printAbundant(limit);

	return 0;
}

int sumProperDivisors(const int num)
{
	int result = 1;

	for (int i = 2; i <= std::sqrt(num); i++)
	{
		if (num % i == 0)
		{
			if (i == (num / i))
				result += i;
			else
				result += (i + num / i);
		}
	}

	return result;
}

void printAbundant(const int limit)
{
	for (int num = 10; num <= limit; num++)
	{
		int sum = sumProperDivisors(num);

		if (sum > num)
			std::cout << num << " ; abundance = " << sum - num << std::endl;
	}
}
