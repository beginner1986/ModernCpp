#pragma once

#include <array>
#include <sstream>

class IPv4
{
private:
	std::array<unsigned char, 4> data;

public:
	constexpr IPv4() : data{ {0} } {}
	constexpr IPv4(unsigned char const a, unsigned char const b,
		unsigned char const c, unsigned char const d) : data{ {a, b, c, d} } {}
	constexpr IPv4(unsigned long a) :
		data{ {
			static_cast<unsigned char>((a >> 24) & 0xFF),
			static_cast<unsigned char>((a >> 16) & 0xFF),
			static_cast<unsigned char>((a >> 8) & 0xFF),
			static_cast<unsigned char>((a & 0xFF))
	} } {}
	IPv4(IPv4 const& other) : data(other.data) {}

	IPv4& operator=(IPv4 const& other) noexcept
	{
		data = other.data;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const IPv4& a)
	{
		os  << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);

		return os;
	}

	friend std::istream& operator>>(std::istream& is, IPv4& a)
	{
		char d1, d2, d3;
		int b1, b2, b3, b4;

		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

		if (d1 == '.' && d2 == '.' && d3 == '.')
			a = IPv4(b1, b2, b3, b4);
		else
			is.setstate(std::ios_base::failbit);

		return is;
	}

	std::string toString() const
	{
		std::stringstream sstr;
		sstr << *this;
		return sstr.str();
	}

	constexpr unsigned long toULong() const noexcept
	{
		return (static_cast<unsigned long>(data[0]) << 24) |
			(static_cast<unsigned long>(data[1]) << 16) |
			(static_cast<unsigned long>(data[2]) << 8) |
			static_cast<unsigned long>(data[3]);
	}
};