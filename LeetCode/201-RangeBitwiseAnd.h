#include <iostream>
using namespace std;

// �������������ְ�λ��Ľ�����������ֵĹ���ǰ׺����һ�����ԣ�����β�������ֵĹ���ǰ׺
// ����ǰ i λ����ͬ���� i+1 λ��ʼ��ͬ�������������������Ե� i+1 λ�� 0 �� 1
// �������������������ֱ�Ϊ 0111... �� 1000... ��ɵ� i+1 λ�� 0 �� 1 ������
// ��ˣ���������������λ��Ľ������β�������Ĺ���ǰ׺���󹫹�ǰ׺������λ��Ҳ������ȥĩβ 1��ֱ�� m>=n

class Solution_201_Shift {
public:
	int rangeBitwiseAnd(int left, int right) {
		int shift = 0;
		while (left < right) {
			left >>= 1;
			right >>= 1;
			++shift;
		}
		return left << shift;
	}
};

class Solution_201_BrianKernighan {
public:
	int rangeBitwiseAnd(int left, int right) {
		while (left < right) {
			right &= (right - 1);
		}
		return right;
	}
};

void test_201() {
	cout << (Solution_201_BrianKernighan().rangeBitwiseAnd(2, 7) == 0) << endl;
}