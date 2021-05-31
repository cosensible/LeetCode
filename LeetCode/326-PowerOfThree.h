#include <iostream>
using namespace std;

class Solution_326 {
public:
	// 不断整除 3，直至不能整除，判断最终是否为 1
	bool isPowerOfThree(int n) {
		if (n < 1) return false;
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
};

class Solution_326_Faster {
public:
	// int 范围内 3 的最大整数次幂为 y=1162261467，因为 3 是质数，y 的因数只有 3 和 1，因此只有 3 的幂能被 y 整除
	bool isPowerOfThree(int n) {
		if (n < 1) return false;
		return 1162261467 % n == 0;
	}
};

void test_326() {
	cout << (Solution_326().isPowerOfThree(27) == true && Solution_326_Faster().isPowerOfThree(45) == false) << endl;
}