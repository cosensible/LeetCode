#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_45 {
public:
	int jump(vector<int>& nums) {
		int pos = 0;   // 这一跳能到达的最远位置
		int nxPos = 0; // 下一跳能到达的最远位置
		int ans = 0;
		if (nums.size() < 2) return 0;

		for (int i = 0; i < nums.size(); ++i) {
			// 如果当前位置超出这一跳的末尾，无法到达终点
			if (i > pos) { return -1; }
			// 求下一跳能够到达的最远位置
			nxPos = max(nxPos, nums[i] + i);
			// 如果下一跳最远位置超过终点，加上下一跳返回结果
			if (nxPos >= nums.size() - 1) {
				return ans + 1;
			}
			// 到达这一跳的末尾，已经求得下一跳能够到达的最远位置，开启下一跳
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