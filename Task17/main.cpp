// implement class template for 2-dimentionacl array container
#include <iostream>
#include <iterator>

#include "Array2d.h"

int main()
{
	std::cout << "array made by initializer list: ";
	Array2d<int, 2, 3> a{ 1, 2, 3, 4, 5, 6 };
	for (size_t i = 0; i < a.size(1); i++)
		for (size_t j = 0; j < a.size(2); j++)
			a(i, j) *= 2;
	std::cout << "OK" << std::endl;

	std::cout << "array print by std::copy: ";
	std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "array fill: ";
	Array2d<int, 2, 3> b;
	b.fill(1);
	std::cout << "OK" << std::endl;

	std::cout << "array swap: ";
	a.swap(b);
	std::cout << "OK" << std::endl;

	std::cout << "printArray2d(b): " << std::endl;
	printArray2d(b);

	// std::move transfers values without having a copy,
	// so function call printArray2d(b) would cause a runtime error!
	std::cout << "array by std::move: ";
	Array2d<int, 2, 3> c(std::move(b));
	std::cout << "OK" << std::endl;

	std::cout << "printArray2d(c): " << std::endl;
	printArray2d(c);

	return 0;
}