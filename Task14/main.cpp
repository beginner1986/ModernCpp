// verify if given number is correct ISBN-10
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

bool validateIsbn(const std::string_view isbn);

int main()
{
	// correct test example: 0205080057
	std::string input;
	std::cout << "ISBN-10: ";
	std::cin >> input;

	std::cout << (validateIsbn(input) ? "OK" : "Wrong") << std::endl;

	return 0;
}

bool validateIsbn(const std::string_view isbn)
{
	bool result = false;

	if (isbn.size() == 10 && std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
	{
		int w = 10;
		int sum = std::accumulate(std::begin(isbn), std::end(isbn), 0,
			[&w](const int total, const char c) {
				return total + w-- * (c - '0');
		});

		result = !(sum % 11);
	}

	return result;
}