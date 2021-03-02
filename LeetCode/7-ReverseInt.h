#include <iostream>
using namespace std;

class Solution_7 {
public:
	int reverse(int x) {
		int ans = 0;
		while (x != 0) {
			int val = x % 10; // ����������, ���� 0~9; �Ը�������, ���� -9~0
			x /= 10;
			// �������: ans*10+val>INT_MAX; �������: ans*10+val<INT_MIN
			if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && val > 7) return 0;
			if (ans < INT_MIN / 10 || ans == INT_MIN / 10 && val < -8) return 0;
			ans = ans * 10 + val;
		}
		return ans;
	}
};

void test_7() {
	cout << (Solution_7().reverse(-423) == -324) << endl;
}