#include <iostream>
using namespace std;

class Solution_461 {
public:
	int hammingDistance(int x, int y) {
		int vxor = x ^ y; // ����������� 1 �ĸ���
		int ans = 0;
		while (vxor) {
			++ans;
			vxor = vxor & (vxor - 1); // �������ұߵ� 1
		}
		return ans;
	}
};

void test_461() {
	cout << (Solution_461().hammingDistance(1, 4) == 2) << endl;
}