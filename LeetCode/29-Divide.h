#include <iostream>
using namespace std;

class Solution_29 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		// INT_MIN/-1 ����������� INT_MAX
		if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
		// ���Ϊ������������Ϊ����
		int sign = (dividend ^ divisor) < 0 ? -1 : 1;
		// ����������ת��Ϊ����
		dividend = dividend > 0 ? -dividend : dividend;
		divisor = divisor > 0 ? -divisor : divisor;

		int ans = sign * div(dividend, divisor);
		return ans;
	}

private:
	int div(int a, int b) {
		if (a > b) return 0;   // a �ľ���ֵ��С��ֱ�ӷ��� 0
		int cnt = 1, tb = b;   // cnt: ͳ�� a �� b �ĸ�����tb: b �� 2^n ��
		while (a - tb <= tb) { // a<=tb+tb����ֹ���
			cnt += cnt;        // ��������
			// ���������, a �����ܱ� tb+tb ��С
			if (tb < INT_MIN - tb) break;
			tb += tb;
		}
		return cnt + div(a - tb, b); // �ۼ�ʣ�µ����а��� b �ĸ���
	}
};


void test_29() {
	// ����ֱ��д -2147483648���ȼ��� tmp=2147483648��a=-tmp���������
	int a = -2147483647 - 1, b = -1;
	cout << (Solution_29().divide(a, b) == INT_MAX) << endl;
}