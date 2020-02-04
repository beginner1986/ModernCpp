// print all the numners divisible by 3 and 5

#include <iostream>

int main()
{
	int limit;
	std::cout << "Type the limit: ";
	std::cin >> limit;

	long long result = 0;
	for (unsigned int i = 1; i <= limit; i++)
		if (i % 3 == 0 || i % 5 == 0)
			result += i;

	std::cout << "The result is " << result << std::endl;
	std::cin.get();

	return 0;
}