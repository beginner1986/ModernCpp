#pragma once
#include "quantity.h"

namespace temperature
{
	template <scale S, scale R>
	struct conversion_traits
	{
		static double convert(double const value) = delete;
	};

	template<>
	struct conversion_traits<scale::celsius, scale::fahrenheit>
	{
		static double convert(double const value)
		{
			return (value * 9) / 5 + 32;
		}
	};

	template<>
	struct conversion_traits<scale::fahrenheit, scale::celsius>
	{
		static double convert(double const value)
		{
			return (value - 32) * 5 / 9;
		}
	};

	template<>
	struct conversion_traits<scale::celsius, scale::kelvin>
	{
		static double convert(double const value)
		{
			return value + 273.15;
		}
	};

	template<>
	struct conversion_traits<scale::kelvin, scale::celsius>
	{
		static double convert(double const value)
		{
			return value - 273.15;
		}
	};

	template<>
	struct conversion_traits<scale::fahrenheit, scale::kelvin>
	{
		static double convert(double const value)
		{
			return (value + 459.67) * 5 / 9;
		}
	};

	template<>
	struct conversion_traits<scale::kelvin, scale::fahrenheit>
	{
		static double convert(double const value)
		{
			return value * 9 / 5 - 459.67;
		}
	};

	template <scale S, scale R>
	constexpr quantity<R> temperature_cast(quantity<S> const q)
	{
		return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
	}
}