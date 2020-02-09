// implement general pourpose function to insert any number of elements
// in the end of contrainer having push_back function
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename C, typename... Args>
void push_back(C& c, Args... args) { (c.push_back(args), ...); }	// fold expression - C++ 17 required

int main()
{
	std::vector<int> vec;
	push_back(vec, 1, 2, 3);
	std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl << std::endl;

	std::list<char> lst;
	push_back(lst, 'a', 'b', 'x', 'y', 'z');
	std::copy(std::begin(lst), std::end(lst), std::ostream_iterator<char>(std::cout, " "));

	std::cout << std::endl;
	std::cin.get();
	
	return 0;
}
