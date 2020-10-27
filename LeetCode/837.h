#include <vector>
#include <algorithm>

using namespace std;

class Solution_837 {
public:
	double new21Game(int N, int K, int W) {
		vector<double> p(N + 1, 0), sum(N + 1, 0);
		p[0] = 1;
		sum[0] = 1;
		for (int i = 1; i <= N; i++) {
			int r = min(K - 1, i - 1), l = max(0, i - W);
			if (l == 0)
				p[i] = sum[r] / W;
			else
				p[i] = (sum[r] - sum[l - 1]) / W;
			sum[i] = sum[i - 1] + p[i];
		}
		return sum[N] - sum[K - 1];
	}
};