#include <iostream>
using namespace std;


// Ҫ��ĩβ���� 0����Ҫ���� 2 �� 5��2 ���������� 5 ������������ֻҪͳ������ 5 ������
// ÿ�� 5 �������� 1 �� 5��ÿ�� 25 �������� 2 �� 5��ÿ�� 125 ���� ���� 3 �� 5��...
// ans = n/5 + n/5^2 + n/5^3 + ...
// �������ʽ���㣬��ĸ����������ÿ�ν� n/5 ��ӵ� ans �ϣ�ֱ�� n Ϊ 0

class Solution_172 {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		while (n > 0) {
			n /= 5;
			ans += n;
		}
		return ans;
	}
};

void test_172() {
	cout << (Solution_172().trailingZeroes(26) == 6) << endl;
}