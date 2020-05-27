
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int input_down_boundary;
	int input_top_boundary;

	std::cout << "Down bounadry: ";
	std::cin >> input_down_boundary;
	std::cout << "Top boundary: ";
	std::cin >> input_top_boundary;

	int real_down_boundary = std::max(input_down_boundary, 0);
	int real_top_boundary = std::max(input_top_boundary, 0);

	if (real_down_boundary > real_top_boundary) {
		std::swap(real_down_boundary, real_top_boundary);
	}

	std::vector<int> primes(sqrt(real_top_boundary) + 1, 1);
	primes[0] = 0;
	primes[1] = 0;

	int sq = sqrt(primes.size());
	for (int a = 2; a < sq; ++a) {
		if (primes[a]) {
			for (int b = a * a; b < primes.size(); b += a) {
				primes[b] = 0;
			}
		}
	}


	int primes_count = 0;

	auto isPrime = [&primes](int n) {
		int sqrt_n = sqrt(n);
		for (int a = 2; a <= sqrt_n; ++a) {
			if (primes[a]) {
				if (n % a == 0) {
					return false;
				}
			}
		}
		return true;
	};

	for (int a = std::max(real_down_boundary, 2); a <= real_top_boundary; ++a) {
		if (isPrime(a)) primes_count++;
	}

	std::cout << "There are " << primes_count << " primes between " << input_down_boundary << " and " << input_top_boundary << '\n';

	return 0;
}
