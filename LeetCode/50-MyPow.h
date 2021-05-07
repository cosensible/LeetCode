#include <iostream>
using namespace std;

class Solution_50 {
public:
	double myPow(double x, int n) {
		if (n == 0 || x == 1) return 1; // 1^n x^0 都是 1
		if (x == 0) return 0; // 0^(-) 不合法 0^(+)=0

		int m = n > 0 ? -n : n; // 负数能表示的范围更大，包含 -2147483648
		double y = power(x, m); // m 为负数，但求的是 x^|m|，借鉴快速乘法
		if (n < 0) y = 1.0 / y;
		return y;
	}

private:
	double power(double x, int n) {
		if (n == 0) return 1; // 终止条件
		int m = -1;
		double y = x;
		while (m >= n - m) { // 防止溢出
			y *= y;
			m += m;
		}
		y *= power(x, n - m); // 注意是相乘
		return y;
	}
};

void test_50() {
	double res = Solution_50().myPow(2.1, 3);
	cout << (abs(res - 9.261) < 1e-5) << endl;
}