#include <iostream>
#include <iomanip>
#include <ctime>
#include <boost/random.hpp>

class RandomGenerator {
	public:
		RandomGenerator() {
			generator.seed(std::time(0));
		}
		double get01() {
			return distribution(generator);
		}
	private:
		boost::mt19937 generator;
		boost::uniform_01<> distribution;
};

int main() {
	RandomGenerator random;
	size_t maximum;
	std::cin >> maximum;
	for (size_t i = 0; i < maximum; ++i) {
		double x = random.get01();
		std::cout << std::fixed << std::setprecision(3)
			<< x << std::endl;
	}
	return 0;
}
