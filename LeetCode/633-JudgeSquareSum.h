#include <cmath>
#include <iostream>
using namespace std;

class Solution_633 {
public:
	// ˫ָ���� [0,sqrt(c)] �о٣���������֮��һ��
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