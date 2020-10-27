#include <iostream>
#include <vector>

using namespace std;

class Solution_31 {
public:
	// �����κθ������еĽ�������, û�б�֮���������
	// �Ӻ���ǰ�ҵ���һ�������[i-1,i], [i,n-1]Ϊ��������
	// Ҫ���ֵ�����һ������, ����[i,n-1]������СԪ��nums[j], ʹnums[j]>nums[i-1],
	// ����nums[j]��nums[i-1], �ٽ�����[i,n-1]��Ϊ˳��, ��õ���һ������
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1;
		for (; i > 0; --i) { // �������
			if (nums[i] > nums[i - 1]) break;
		}
		if (i > 0) { // i==0, �������
			for (int j = n - 1; j >= i; --j) {
				if (nums[j] > nums[i - 1]) {
					swap(nums[i - 1], nums[j]);
					break;
				}
			}
		}
		// �������Ϊ˳��
		for (int j = n - 1; j > i; --j, ++i) {
			swap(nums[i], nums[j]);
		}
	}
};

void test_31() {
	vector<int> vi = { 1,4,5,3,2 };
	Solution_31().nextPermutation(vi);
	vector<int> exp = { 1,5,2,3,4 };
	cout << (exp == vi) << endl;
}