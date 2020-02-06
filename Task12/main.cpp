// print number less than 1 million that gives the longest Collatz sequence and find his lenght
#include <iostream>
#include <vector>
#include <utility>

std::pair<unsigned long long, long> longestCollatz(const unsigned long long limit);

int main()
{
	unsigned long long limit = 1000000u;
	auto result = longestCollatz(limit);

	std::cout << "parameter: " << result.first << std::endl;
	std::cout << "length: " << result.second << std::endl;
	std::cin.get();

	return 0;
}

std::pair<unsigned long long, long> longestCollatz(const unsigned long long limit)
{
	long length = 0;
	unsigned long long num = 0;
	std::vector<int> temp(limit + 1, 0);

	for (unsigned long long i = 2; i <= limit; i++)
	{
		auto n = i;
		long steps = 0;

		while (n != 1 && n >= 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = n * 3 + 1;

			steps++;
		}

		temp[i] = steps + temp[n];

		if (temp[i] > length)
		{
			length = temp[i];
			num = i;
		}
	}

	return std::make_pair(num, length);
}