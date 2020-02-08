// print all the IPv4 adresses in the given range
#include <iostream>

#include "IPv4.h"

int main()
{
	IPv4 min, max;

	std::cout << "min IP limit: ";
	std::cin >> min;
	std::cout << "max IP limit: ";
	std::cin >> max;

	if (max > min)
	{
		for (IPv4 i = min; i <= max; i++)
		{
			std::cout << i << std::endl;
		}
	}
	else
	{
		std::cerr << "Min IP must be lower value than max IP!" << std::endl;
	}

	return 0;
}