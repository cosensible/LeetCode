#include <vector>
#include <iostream>
using namespace std;

class Solution_81 {
public:
	// �� 33 ��Ψһ��֮ͬ�����������е�Ԫ�ؿ����ظ�����
	// ���ܳ��� nums[l]==nums[m]==nums[r] ������������޷��ж��м�Ԫ������������黹���Ұ�����
	bool search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (target == nums[m]) return true;
			// �м�Ԫ�ص�����������Ԫ�أ��޷��ж��м�Ԫ������������黹���Ұ�����
			// ��Ҫ������߽硢�����ұ߽�
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				while (l <= r && nums[l] == nums[m])++l;
				while (l <= r && nums[r] == nums[m])--r;
				continue;
			}
			// �м�Ԫ�ش����ұ�Ԫ�أ���Ԫ��λ��������飬[l,m] Ϊ����������
			if (nums[m] > nums[r]) {
				if (target >= nums[l] && target < nums[m]) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			else { // �м�Ԫ��λ���Ұ����飬[m,r] Ϊ����������
				if (target > nums[m] && target <= nums[r]) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return false;
	}
};


void test_81() {
	vector<int> nums = { 1,0,1,1,1 };
	cout << (Solution_81().search(nums, 0)) << endl;
}