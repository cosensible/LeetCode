#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_45 {
public:
	int jump(vector<int>& nums) {
		int pos = 0;   // ��һ���ܵ������Զλ��
		int nxPos = 0; // ��һ���ܵ������Զλ��
		int ans = 0;
		if (nums.size() < 2) return 0;

		for (int i = 0; i < nums.size(); ++i) {
			// �����ǰλ�ó�����һ����ĩβ���޷������յ�
			if (i > pos) { return -1; }
			// ����һ���ܹ��������Զλ��
			nxPos = max(nxPos, nums[i] + i);
			// �����һ����Զλ�ó����յ㣬������һ�����ؽ��
			if (nxPos >= nums.size() - 1) {
				return ans + 1;
			}
			// ������һ����ĩβ���Ѿ������һ���ܹ��������Զλ�ã�������һ��
			if (i == pos) {
				pos = nxPos;
				++ans;
			}
		}
		return ans;
	}
};

void test_45() {
	vector<int> nums = { 2,0,0,1,4 };
	cout << (Solution_45().jump(nums) == -1) << endl;
}