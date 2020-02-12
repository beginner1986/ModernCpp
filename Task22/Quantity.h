#pragma once
#include <cmath>
#include "Scale.h"

namespace temperature
{
	template <Scale S>
	class Quantity
	{
	private:
		const double amount;

	public:
		constexpr explicit Quantity(double const a)
			: amount(a) {}

		explicit operator double() const { return amount; }

		template <Scale S>
		inline bool operator==(Quantity<S> const& lhs, Quantity<S> const& rhs)
		{
			const double eps = 0.001;
			
			return abs(static_cast<double>(lhs) - static_cast<double>(rhs)) < eps;
		}

		template <Scale S>
		inline bool operator!=(Quantity<S> const& lhs, Quantity<S> const& rhs)
		{
			return !(lhs == rhs);
		}

		template <Scale S>
		inline bool operator<(Quantity<S> const& lhs, Quantity<S> const& rhs)
		{
			return static_cast<double>(lhs) < static_cast<double>(rhs);
		}

		template <Scale S>
		inline bool operator>(Quantity<S> const& lhs, Quantity<S> const& rhs)
		{
			return rhs < lhs;
		}

		template <Scale S>
		inline bool operator<=(Quantity<S> const& lhs, Quantity<S> sont& rhs)
		{
			return !(lhs > rhs);
		}

		template <Scale S>
		inline bool operator>=(Quantity<S> const& lhs, Quantity<S> const& rhs)
		{
			return !(lhs < rhs);
		}

		template <Scale S>
		constexpr Quantity<S> operator+(Quantity<S> const& q1, Quantity<S> const& q2)
		{
			return static_cast<double>(q1) + static_cast<double>(q2);
		}

		template <Scale S>
		constexpr Quantity<S> operator-(Quantity<S> const& q1, Quantity<S> const& q2)
		{
			return static_cast<double>(q1) - static_cast<double>(q2);
		}
	};
}