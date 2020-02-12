#pragma once
#include <cmath>
#include "scale.h"

namespace temperature
{
	template <scale S>
	class quantity
	{
	private:
		const double amount;

	public:
		constexpr explicit quantity(double const a)
			: amount(a) {}

		explicit operator double() const { return amount; }
	};

	template <scale S>
	inline bool operator==(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		const double eps = 0.001;

		return abs(static_cast<double>(lhs) - static_cast<double>(rhs)) < eps;
	}

	template <scale S>
	inline bool operator!=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <scale S>
	inline bool operator<(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return static_cast<double>(lhs) < static_cast<double>(rhs);
	}

	template <scale S>
	inline bool operator>(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return rhs < lhs;
	}

	template <scale S>
	inline bool operator<=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs > rhs);
	}

	template <scale S>
	inline bool operator>=(quantity<S> const& lhs, quantity<S> const& rhs)
	{
		return !(lhs < rhs);
	}

	template <scale S>
	constexpr quantity<S> operator+(quantity<S> const& q1, quantity<S> const& q2)
	{
		return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
	}

	template <scale S>
	constexpr quantity<S> operator-(quantity<S> const& q1, quantity<S> const& q2)
	{
		return quantity<S>(static_cast<double>(q1) - static_cast<double>(q2));
	}
}