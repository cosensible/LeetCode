#include <iostream>
using namespace std;

class Solution_461 {
public:
	int hammingDistance(int x, int y) {
		int vxor = x ^ y; // 计算异或结果中 1 的个数
		int ans = 0;
		while (vxor) {
			++ans;
			vxor = vxor & (vxor - 1); // 消掉最右边的 1
		}
		return ans;
	}
};

void test_461() {
	cout << (Solution_461().hammingDistance(1, 4) == 2) << endl;
}