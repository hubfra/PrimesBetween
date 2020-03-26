
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int left_boundary;
	int right_boundary;
	int primes_count = 0;

	cout << "Left bounadry: ";
	cin >> left_boundary;
	cout << "Right boundary: ";
	cin >> right_boundary;

	vector<int> primes(sqrt(right_boundary) + 1, 1);
	primes[0] = 0;
	primes[1] = 0;

	for (int a = 2; a < primes.size(); a++)
	{
		if (primes[a] == 1)
		{
			for (int b = a * 2; b < primes.size(); b += a)
			{
				primes[b] = 0;
			}
		}
	}

	for (int a = left_boundary >= 2 ? left_boundary : 2; a <= right_boundary; a++)
	{
		bool is_prime = true;

		for (int b = 2; b <= sqrt(a); b++)
		{
			if (primes[b] == 1)
			{
				if (a % b == 0)
				{
					is_prime = false;
					break;
				}
			}
		}

		if (is_prime)
		{
			primes_count++;
		}
	}

	cout << "Between " << left_boundary << " and " << right_boundary << " there are " << primes_count << " primes\n";

	return 0;
}