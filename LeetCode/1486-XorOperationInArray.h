#include <iostream>
using namespace std;

class Solution_1486 {
public:
	// ans=start^(start+2)^(start+2*2)^(start+2*3)^...^(start+2*(n-1))
	// prefix=s^(s+1)^(s+2)^(s+3)^...^(s+n-1)  s=start/2
	// s^(s+1)^(s+2)^(s+3)^...^(s+n-1)=xor[1,s-1]^xor[1,s+n-1]
	// �� ans ������Ԫ������һλ�õ� prefix���������ս��Ҫ�� prefix ����һλ�����������һλ
	// �����������������ֵ�����������������ʣ����� i ���� Z���� 4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0
	int xorOperation(int n, int start) {
		int s = start >> 1;
		int b0 = n & start & 1;
		int prefix = xorn(s - 1) ^ xorn(s + n - 1);
		return prefix << 1 | b0;
	}

private:
	int xorn(int x) {
		switch (x % 4) {
		case 0:return x;
		case 1:return 1;
		case 2:return x + 1;
		}
		// case 3
		return 0;
	}
};

void test_1486() {
	cout << (Solution_1486().xorOperation(4, 3) == 8) << endl;
}