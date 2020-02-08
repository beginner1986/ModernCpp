#pragma once

#include <vector>
#include <stdexcept>

template<class T, size_t R, size_t C>
class Array2d
{
private:
	std::vector<T> arr;

	typedef T* iterator;
	typedef T const* const_iterator;
public:
	Array2d() : arr(R* C) {}
	explicit Array2d(std::initializer_list<T> init) : arr(init) {}

	constexpr T* data() noexcept { return arr.data(); }
	constexpr T const* data() const noexcept { return arr.data(); }

	constexpr T& at(const size_t r, const size_t c) { return arr[r * C + c]; }
	constexpr T const& at(const size_t r, const size_t c) const { return arr[r * C + c]; }

	constexpr T& operator()(const size_t r, const size_t c) { return arr[r * C + c]; }
	constexpr T const& operator()(const size_t r, const size_t c) const { return arr[r * C + c]; }

	constexpr bool empty() const noexcept { return R == 0 || C == 0; }

	constexpr size_t size(const int rank) const
	{
		if (rank == 1)
			return R;
		else if (rank == 2)
			return C;
		throw std::out_of_range("size() parameter out of range!");
	}

	void fill(const T& value) { std::fill(std::begin(arr), std::end(arr), value);	}

	void swap(Array2d& other) noexcept { arr.swap(other.arr); }

	const_iterator begin() const { return arr.data(); }
	const_iterator end() const { return arr.data() + arr.size(); }

	iterator begin() { return arr.data(); }
	iterator end() { return arr.data() + arr.size(); }
};

template<class T, size_t R, size_t C>
void printArray2d(const Array2d<T, R, C>& array)
{
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			std::cout << array.at(i, j) << ' ';
		}
		std::cout << std::endl;
	}
}
