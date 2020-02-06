// find pi value with 0.01 accuracy using Monte Carlo method

#include <iostream>
#include <iomanip>
#include <random>
#include <array>

template<typename E = std::mt19937,
	typename D = std::uniform_real_distribution<> >
	double computePi(E& engine, D& dist, const int samples = 1000000);

int main()
{
	std::random_device rd;
	auto seedData = std::array<int, std::mt19937::state_size> {};
	std::generate(std::begin(seedData), std::end(seedData), std::ref(rd));
	std::seed_seq seq(std::begin(seedData), std::end(seedData));
	auto eng = std::mt19937{ seq };
	auto dist = std::uniform_real_distribution<>{ 0, 1 };

	for (auto i = 0; i < 10; i++)
		std::cout << std::setprecision(3) << computePi(eng, dist) << std::endl;

	return 0;
}

template<typename E = std::mt19937,
	typename D = std::uniform_real_distribution<> >
double computePi(E& engine, D& dist, const int samples)
{
	auto hitCount = 0;
	for (int i = 0; i < samples; i++)
	{
		auto x = dist(engine);
		auto y = dist(engine);

		if (y <= std::sqrt(1 - std::pow(x, 2)))
			hitCount++;
	}

	return 4.0 * hitCount / samples;
}
