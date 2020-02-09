// implement a function template that will take any number of arguments and return the minium value
#include <iostream>
#include <functional>

// ----------------- functions declaration ---------------------
template<typename T>
T minimum(const T a, const T b);

template<typename T1, typename... T>
T1 minimum(const T1 a, const T... args);

template<class Compare, typename T>
T minimumCmp(Compare compare, const T a, const T b);

template<class Compare, typename T1, typename... T>
T1 minimumCmp(Compare compare, const T1 a, T... args);

// ------------------------ main -------------------------------
int main()
{
	std::cout << minimum(10, 100, 23, 8, 9) << std::endl;
	std::cout << minimum(1.0, 10.0, 2.3, 0.8, 0.9) << std::endl;
	std::cout << minimum('d', 'n', 'f', 'b') << std::endl;

	std::cout << minimumCmp(std::less<>(), 10, 100, 23, 8, 9) << std::endl;
	std::cout << minimumCmp(std::less<>(), 1.0, 10.0, 2.3, 0.8, 0.9) << std::endl;
	std::cout << minimumCmp(std::less<>(), 'd', 'n', 'f', 'b') << std::endl;

	return 0;
}

// ----------------- functions definition ----------------------
template<typename T>
T minimum(const T a, const T b) { return (a < b ? a : b); }

template<typename T1, typename... T>
T1 minimum(const T1 a, const T... args) { return minimum(a, minimum(args...)); }

template<class Compare, typename T>
T minimumCmp(Compare compare, const T a, const T b) { return (compare(a, b) ? a : b); }

template<class Compare, typename T1, typename... T>
T1 minimumCmp(Compare compare, const T1 a, T... args) 
{
	return minimumCmp(compare, a, minimumCmp(compare, args...));
}