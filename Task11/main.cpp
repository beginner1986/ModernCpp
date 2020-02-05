// convert arabic number to roman

#include <iostream>
#include <vector>
#include <utility>

std::string toRoman(int val);

int main()
{
	int num;
	std::cout << "number = ";
	std::cin >> num;

	std::cout << toRoman(num) << std::endl;

	return 0;
}

std::string toRoman(int val)
{
	std::vector<std::pair<int, std::string> > romans = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
		{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
	};

	std::string result = "";

	for (std::pair<int, std::string>& pair : romans)
	{
		while (val >= pair.first)
		{
			result += pair.second;
			val -= pair.first;
		}
	}

	return result;
}
