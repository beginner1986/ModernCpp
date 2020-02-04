// print all the friend numbers pairs below 1 000 000

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

int sumProperDivisors(const int num);

int main()
{
	int limit = 1000000;
	std::set<std::pair<int, int> > result;

	for (int num = 4; num < limit; num++)
	{
		int sum1 = sumProperDivisors(num);
		if (sum1 < limit)
		{
			int sum2 = sumProperDivisors(sum1);

			if (sum2 == num && sum1 != num)
			{
				result.insert(std::make_pair(std::min(num, sum1), std::max(num, sum1)));
			}
		}
	}

	for (std::pair<int, int> p : result)
		std::cout << p.first << " - " << p.second << std::endl;

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
