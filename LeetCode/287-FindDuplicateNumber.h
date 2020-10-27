#include <vector>
#include <iostream>

using namespace std;


// 若数组大小为 n, 且无重复元素, 则对于某元素 x, 小于等于 x 的元素数量为 x
// 若个数 >x, 说明 [1,x] 有重复元素, 否则 [x+1,n] 有重复元素
// 因此, 可利用二分搜索查找重复元素
class Solution_287_1 {
public:
	int findDuplicate(vector<int>& nums) {
		int l = 1, r = nums.size() - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			int count = 0;
			for (int n : nums) {
				if (n <= m) { count++; }
			}
			if (count > m) { r = m; }
			else { l = m + 1; }
		}
		return l;
	}
};

// 数组大小为 n+1, 索引为 0~n, 数组元素为 1~n
// 数组元素可以看作下一个数的索引, 从而形成一个链表
// 数组有重复元素表明至少有两个节点指向该元素, 因此该元素为链表环的入口
class Solution_287 {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		fast = 0;
		while (fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return fast;
	}
};

void test_287() {
	vector<int> vi = { 1,3,4,2,2 };
	vector<int> vi1 = { 3,1,3,4,2 };
	cout << ((Solution_287().findDuplicate(vi) == 2) &&
		(Solution_287().findDuplicate(vi1) == 3)) << endl;
}