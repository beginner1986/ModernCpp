// check if container contains any, all or none of given elements
#include <iostream>
#include <vector>
#include <list>
#include <array>

//#define NDEBUG
#include <cassert>

template<class C, class T>
bool contains(C const& c, T const& value)
{
	return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class... T>
bool contains_any(C const& c, T&&... value)	// fold expression - C++ 17
{
	return (... || contains(c, value));
}

template<class C, class... T>
bool contains_all(C const& c, T&&... value)
{
	return (... && contains(c, value));
}

template<class C, class... T>
bool contains_none(C const& c, T&&... value)
{
	return !contains_any(c, std::forward<T>(value)...);	// std::forward - C++ 14
}

int main()
{
	std::vector<int> v{ 1, 5, 10, 3, 2 };
	assert(contains_any(v, 2, 3, 4, 5));

	std::list<int> l{ 1, 5, 10, 3, 2 };
	assert(contains_all(l, 5, 10, 1));

	std::array<int, 5> a{ 1, 5, 10, 3, 2 };
	assert(contains_none(a, 6, 0, 4));

	return 0;
}
