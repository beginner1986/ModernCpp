// print natural binary representation, Gray code 
// and decoded Gray code for all 5-bit numbers

#include <iostream>
#include <bitset>

unsigned int grayEncode(const unsigned int num);
unsigned int grayDecode(unsigned int num);
std::string toBinary(unsigned int num);

int main()
{
	std::cout << "Decimal value\tBinary value\tGray code\tdecoed Gray" << std::endl;
	for (int i = 0; i < 32; i++)
	{
		unsigned int gray = grayEncode(i);

		std::cout << i << "\t\t"
			<< toBinary(i) << "\t\t"
			<< toBinary(gray) << "\t\t"
			<< toBinary(grayDecode(gray)) << std::endl;
	}
	
	std::cin.get();

	return 0;
}

unsigned int grayEncode(const unsigned int num)
{
	return num ^ (num >> 1);
}

unsigned int grayDecode(unsigned int num)
{
	for (unsigned int bit = 1u << 5; bit > 1; bit >>= 1)
	{
		if (num & bit)
			num ^= bit >> 1;
	}

	return num;
}

std::string toBinary(unsigned int num)
{
	return std::bitset<5>(num).to_string();
}
