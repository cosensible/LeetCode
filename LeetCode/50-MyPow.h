#include <iostream>
using namespace std;

class Solution_50 {
public:
	double myPow(double x, int n) {
		if (n == 0 || x == 1) return 1; // 1^n x^0 ���� 1
		if (x == 0) return 0; // 0^(-) ���Ϸ� 0^(+)=0

		int m = n > 0 ? -n : n; // �����ܱ�ʾ�ķ�Χ���󣬰��� -2147483648
		double y = power(x, m); // m Ϊ������������� x^|m|��������ٳ˷�
		if (n < 0) y = 1.0 / y;
		return y;
	}

private:
	double power(double x, int n) {
		if (n == 0) return 1; // ��ֹ����
		int m = -1;
		double y = x;
		while (m >= n - m) { // ��ֹ���
			y *= y;
			m += m;
		}
		y *= power(x, n - m); // ע�������
		return y;
	}
};

void test_50() {
	double res = Solution_50().myPow(2.1, 3);
	cout << (abs(res - 9.261) < 1e-5) << endl;
}