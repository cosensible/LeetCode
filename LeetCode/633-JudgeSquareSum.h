#include <cmath>
#include <iostream>
using namespace std;

class Solution_633 {
public:
	// 双指针在 [0,sqrt(c)] 列举，就像两数之和一样
	bool judgeSquareSum(int c) {
		for (int i = 0, j = sqrt(c); i <= j;) {
			if (c - i * i > j*j) i++;
			else if (c - i * i < j*j) j--;
			else return true;
		}
		return false;
	}
};

void test_633() {
	cout << (Solution_633().judgeSquareSum(13)) << endl;
}