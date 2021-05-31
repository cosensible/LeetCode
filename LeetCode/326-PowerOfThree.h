#include <iostream>
using namespace std;

class Solution_326 {
public:
	// �������� 3��ֱ�������������ж������Ƿ�Ϊ 1
	bool isPowerOfThree(int n) {
		if (n < 1) return false;
		while (n % 3 == 0) {
			n /= 3;
		}
		return n == 1;
	}
};

class Solution_326_Faster {
public:
	// int ��Χ�� 3 �������������Ϊ y=1162261467����Ϊ 3 ��������y ������ֻ�� 3 �� 1�����ֻ�� 3 �����ܱ� y ����
	bool isPowerOfThree(int n) {
		if (n < 1) return false;
		return 1162261467 % n == 0;
	}
};

void test_326() {
	cout << (Solution_326().isPowerOfThree(27) == true && Solution_326_Faster().isPowerOfThree(45) == false) << endl;
}