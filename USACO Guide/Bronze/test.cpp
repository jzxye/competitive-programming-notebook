	#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

const int BITS = 30;

int main() {
	int n, q;
	std::cin >> n >> q;
	std::vector<long long> costs(n);

	for (long long &x : costs) { std::cin >> x; }

	// precompute minimum costs for power of 2 bucket amounts
	for (int i = 1; i < BITS; i++) {
		if (i >= n) {
			costs.push_back(2LL * costs[i - 1]);
		} else {
			costs[i] = std::min(costs[i], 2LL * costs[i - 1]);
		}
	}

	while (q--) {
		long x;
		std::cin >> x;
		long long curr_cost = 0;
		long long answer = LLONG_MAX;

		while (x > 0) {
			long largest_idx = floor(std::log2(x));
			long overshoot_idx = ceil(std::log2(x));
			// overshoot
			answer = std::min(answer, curr_cost + costs[overshoot_idx]);
			// buy largest power of 2 that doesn't overshoot
			curr_cost += costs[largest_idx];
			x -= 1LL << largest_idx;
		}
		// never overshoot
		answer = std::min(answer, curr_cost);
		std::cout << answer << '\n';
	}
}