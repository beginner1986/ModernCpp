// Create a class representing IPv4 address
#include <iostream>

#include "IPv4.h"

int main()
{
	IPv4 address(192, 168, 0, 1);
	std::cout << address << std::endl;

	IPv4 ip;
	std::cout << ip << std::endl;
	std::cin >> ip;
	if (!std::cin.fail())
		std::cout << ip << std::endl;

	return 0;
}
