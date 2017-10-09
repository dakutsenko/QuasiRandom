#include <iostream>
#include <iomanip>
#include <cassert>

class HaltonSequence {
	public:
		HaltonSequence(int seed, int base):
				index(seed),
				base(base) {
			assert (seed >= 0);
			assert (base > 2);
		}

		double next() {
			double result = 0;
			double f = 1.0 / base;
			int i = index;
			while (i > 0) {
				result += f * (i % base);
				i /= base;
				f /= base;
			}
			++index;
			return result;
		}

	private:
		int index;
		int base;
};

int main() {
	HaltonSequence rnd(0, 3);
	size_t maximum;
	std::cin >> maximum;
	for (size_t i = 0; i < maximum; ++i) {
		std::cout << std::fixed << std::setprecision(3)
			<< rnd.next() << std::endl;
	}
	return 0;
}
