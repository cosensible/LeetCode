#include <iostream>
using namespace std;

class Solution_9 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || x % 10 == 0 && x != 0) return false;
		int y = 0;
		while (x > y) { // ֻ��Ҫת������, ���Է�ֹת�����
			y = y * 10 + x % 10;
			x /= 10;
		}
		return x == y || x == y / 10;
	}
};

void test_9() {
	cout << Solution_9().isPalindrome(12321) << endl;
}