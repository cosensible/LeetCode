#include <iostream>
using namespace std;


// 要在末尾产生 0，需要因子 2 和 5，2 的数量大于 5 的数量，所以只要统计因子 5 的数量
// 每隔 5 个数出现 1 个 5，每隔 25 个数出现 2 个 5，每隔 125 个数 出现 3 个 5，...
// ans = n/5 + n/5^2 + n/5^3 + ...
// 如果按上式计算，分母会溢出，因此每次将 n/5 后加到 ans 上，直至 n 为 0

class Solution_172 {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		while (n > 0) {
			n /= 5;
			ans += n;
		}
		return ans;
	}
};

void test_172() {
	cout << (Solution_172().trailingZeroes(26) == 6) << endl;
}