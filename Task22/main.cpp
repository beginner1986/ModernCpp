// create a small library, to use three temeprature scales: Celsius, Fahrenheit and Kelvin (incl. conversions)
#include <iostream>
#include <cassert>

#include "conversion_traits.h"
#include "literals.h"

int main()
{
	using namespace temperature;
	using namespace temperature_scale_literals;

	auto t1{ 36.6_deg };
	auto t2{ 79.0_f };
	auto t3{ 273.0_k };

	auto tf = temperature_cast<scale::fahrenheit>(t1);
	assert(t1 == temperature_cast<scale::celsius>(tf));
	
	auto tk = temperature_cast<scale::kelvin>(t2);
	assert(t2 == temperature_cast<scale::fahrenheit>(tk));
	
	auto tc = temperature_cast<scale::celsius>(t3);
	assert(t3 == temperature_cast<scale::kelvin>(tc));

	return 0;
}