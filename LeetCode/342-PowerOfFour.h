#include <iostream>
using namespace std;

class Solution_342 {
public:
	// 4 ���������� 2 ���ݣ���ż��λΪ 1 (�� 0 ��ʼ)
	bool isPowerOfFour(int n) {
		return n > 0 && (n & (n - 1)) == 0 && n & 0x55555555;
	}
};

class Solution_342_Another {
public:
	// 4^x=(3+1)^x��ֻ�� 1 ��˲������� 3����� (4^x)%3==1
	bool isPowerOfFour(int n) {
		return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
	}
};

void test_342() {
	cout << (Solution_342().isPowerOfFour(16) == true && Solution_342_Another().isPowerOfFour(8) == false) << endl;
}