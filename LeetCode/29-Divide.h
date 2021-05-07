#include <iostream>
using namespace std;

class Solution_29 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		// INT_MIN/-1 会溢出，返回 INT_MAX
		if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
		// 异或为负数，相除结果为负数
		int sign = (dividend ^ divisor) < 0 ? -1 : 1;
		// 将两个数都转化为负数
		dividend = dividend > 0 ? -dividend : dividend;
		divisor = divisor > 0 ? -divisor : divisor;

		int ans = sign * div(dividend, divisor);
		return ans;
	}

private:
	int div(int a, int b) {
		if (a > b) return 0;   // a 的绝对值较小，直接返回 0
		int cnt = 1, tb = b;   // cnt: 统计 a 中 b 的个数，tb: b 的 2^n 倍
		while (a - tb <= tb) { // a<=tb+tb，防止溢出
			cnt += cnt;        // 个数翻倍
			// 翻倍后溢出, a 不可能比 tb+tb 更小
			if (tb < INT_MIN - tb) break;
			tb += tb;
		}
		return cnt + div(a - tb, b); // 累加剩下的数中包含 b 的个数
	}
};


void test_29() {
	// 不能直接写 -2147483648，等价于 tmp=2147483648，a=-tmp，导致溢出
	int a = -2147483647 - 1, b = -1;
	cout << (Solution_29().divide(a, b) == INT_MAX) << endl;
}