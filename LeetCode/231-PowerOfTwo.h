#include <iostream>
using namespace std;

class Solution_231 {
public:
	// n&(n - 1) 消掉最右边的 1
	bool isPowerOfTwo(int n) {
		return n > 0 && (n&(n - 1)) == 0;
	}
};

class Solution_231_Another {
public:
	// n&(-n) 取最右边的 1
	bool isPowerOfTwo(int n) {
		return n > 0 && (n&(-n)) == n;
	}
};

void test_231() {
	cout << (Solution_231().isPowerOfTwo(16) == true && Solution_231_Another().isPowerOfTwo(3) == false) << endl;
}