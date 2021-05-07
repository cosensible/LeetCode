#include <iostream>
using namespace std;

// 二分查找
class Solution_69_BS {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		int l = 2, r = x;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (m <= x / m) l = m + 1;
			else r = m - 1;
		}
		return r;
	}
};

// 牛顿迭代
class Solution_69_Newton {
public:
	int mySqrt(int x) {
		double t = x;
		while (t*t - x >= 1) t = 0.5*(t + x / t);
		return static_cast<int>(t);
	}
};

void test_69() {
	cout << (Solution_69_Newton().mySqrt(10) == 3) << endl;
}