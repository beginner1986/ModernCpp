#pragma once
#include "quantity.h"

namespace temperature
{
	namespace temperature_scale_literals
	{
		constexpr quantity<scale::celsius> operator "" _deg(long double const amount)
		{
			return quantity<scale::celsius> { static_cast<double>(amount) };
		}

		constexpr quantity<scale::fahrenheit> operator "" _f(long double const amount)
		{
			return quantity<scale::fahrenheit> { static_cast<double>(amount) };
		}

		constexpr quantity<scale::kelvin> operator "" _k(long double const amount)
		{
			return quantity<scale::kelvin> { static_cast<double>(amount) };
		}
	}
}