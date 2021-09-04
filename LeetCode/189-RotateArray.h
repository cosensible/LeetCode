#include <vector>
#include <iostream>
using namespace std;

class Solution_189_Recurrent {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		if (n < 2 || k == 0) return;

		int start = 0; // ÿһ��ѭ������㣬�� n ���� k ʱ��ÿ��ѭ���ص����ʱ��©��һЩԪ��
		int cnt = 0;   // �Ѿ���λ��Ԫ�ص�����
		while (cnt != n) {
			int tmp = nums[start]; // ���汻�滻��Ԫ��
			int idx = start;
			do {
				int next = (idx + k) % n; // Ԫ�ص�Ŀ��λ��
				swap(tmp, nums[next]);
				idx = next;
				cnt++;
			} while (idx != start);
			start++;
		}
	}
};

class Solution_189_Reverse {
public:
	// �ȷ�ת�������飬�ٷֱ�ת������ [0,k) �� [k,n)
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
		k %= n;
		for (int i = 0, j = k - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
		for (int i = k, j = n - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
	}
};

void test_189() {
	vector<int> nums = { 1,2,3,4,5,6 };
	int k = 3;
	Solution_189_Reverse().rotate(nums, k);
	for (int i : nums) cout << i << " ";
	cout << endl;
}