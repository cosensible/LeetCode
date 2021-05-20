#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_135 {
public:
	// 评分高的孩子必须比他两侧的孩子获得更多糖果
	// 左规则：若 ratings[i]>ratings[i-1]，则 candy[i]=candy[i-1]+1
	// 右规则：若 ratings[i]>ratings[i+1]，则 candy[i]=candy[i+1]+1
	// 孩子 i 最终得到的糖果数量为满足左规则和满足右规则的最大值
	int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> cnt(n, 1); // 每个孩子至少一颗糖果
		// 从左到右遍历数组，计算每个孩子在满足左规则时获得的糖果数
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1])
				cnt[i] = cnt[i - 1] + 1;
		}
		// 从右到左遍历数组，计算每个孩子在满足右规则时获得的糖果数，并取左右最大值
		for (int i = n - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1])
				cnt[i] = max(cnt[i], cnt[i + 1] + 1);
		}
		int ans = 0; // 累加每个孩子的糖果数
		for (int i = 0; i < n; ++i) {
			ans += cnt[i];
		}
		return ans;
	}
};


void test_135() {
	vector<int> ratings = { 1,0,2 };
	cout << (Solution_135().candy(ratings) == 5) << endl;
}