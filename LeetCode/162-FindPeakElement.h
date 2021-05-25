#include <vector>
#include <iostream>
using namespace std;


// ���� nums[-1]==nums[n] == -INF���� nums[i]!=nums[i+1]����һ�����ڷ�ֵ
// ��Ϊ��������һ����ֵ���ɣ����Կ��Բ��ö��ַ���Ѱ�ҷ�ֵ
// �� nums[m]>nums[m+1]���� nums[m] �����½��Σ������һ�����ڷ�ֵԪ�� (nums[-1] == -INF)
// ���� nums[m] ���������Σ����Ҳ�һ�����ڷ�ֵԪ�� (nums[n] == -INF)

class Solution_162 {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return -1; // ��Ԫ�أ��޷�ֵ
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			// �м�Ԫ���Ƿ�������Ԫ��
			bool left = m == 0 ? true : nums[m] > nums[m - 1];
			// �м�Ԫ���Ƿ�����ұ�Ԫ��
			bool right = m == n - 1 ? true : nums[m] > nums[m + 1];
			if (left && right) return m; // nums[m] Ϊ��ֵԪ��
			if (nums[m] > nums[m + 1]) r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
};


void test_162() {
	vector<int> nums = { 1,2,1,3,5,6,4 };
	int ans = Solution_162().findPeakElement(nums);
	cout << (ans == 1 || ans == 5) << endl;
}