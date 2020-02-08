// implement class template for 2-dimentionacl array container
#include <iostream>
#include <iterator>

#include "Array2d.h"

int main()
{
	Array2d<int, 2, 3> a{ 1, 2, 3, 4, 5, 6 };
	for (size_t i = 0; i < a.size(1); i++)
		for (size_t j = 0; a.size(2); j++)
			a(i, j) *= 2;

	/*
	std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));

	Array2d<int, 2, 3> b;
	b.fill(1);

	a.swap(b);

	Array2d<int, 2, 3> c(std::move(b));

	std::cout << "a:" << std::endl;
	printArray2d(a);

	std::cout << "b:" << std::endl;
	printArray2d(b);

	std::cout << "c:" << std::endl;
	printArray2d(c);
	*/

	return 0;
}