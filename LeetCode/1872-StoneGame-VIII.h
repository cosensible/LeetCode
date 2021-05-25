#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1872 {
public:
	// 玩家的每一步操作，都是将左侧的 x 枚石子合并，并获取等价的分数，每一轮的分数都是某个前缀和
	// 设 f(i) 表示玩家可选择的下标 u 在范围 [i,n-1] 时，能获得的最大分差
	// 若 Alice 选择 i，她获得 prefix[i] 分，Bob 只能在 [i+1,n-1] 内选择，
	// 由于 Bob 要最小化得分差，他会在 [i+1,n-1] 范围内选择最大差值 f(i+1)，因此得分差为 pre[i]-f(i+1)
	// 若 Alice 不选择 i，说明她要在范围 [i+1,n-1] 内做选择，最大分差为 f(i+1)
	// 最后 f(i) 为两者最大值
	int stoneGameVIII(vector<int>& stones) {
		int n = stones.size();
		if (n < 2) return 0;
		for (int i = 1; i < n; ++i) stones[i] += stones[i - 1];
		int ans = stones[n - 1];
		for (int i = n - 2; i >= 1; --i) {
			ans = max(ans, stones[i] - ans);
		}
		return ans;
	}
};

void test_1872() {
	vector<int> stones = { -1,2,-3,4,-5 };
	cout << (Solution_1872().stoneGameVIII(stones) == 5) << endl;
}