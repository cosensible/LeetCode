#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


// 任意长度为 k 的区间异或结果为 0，有 xor{ nums[i,i+k-1] }=0，xor{ nums[i+1,i+k] }=0，推出 nums[i]^nums[i+k]=0，即 nums[i]==nums[i+k]
// 因此，nums 在修改后是一个以 k 为周期的数组，将 nums 中的元素按 i%k 分为 k 组，修改后每组元素必须相等，且 nums[0]^...^nums[k-1]==0
// 设 f(i,x) 为处理了 [0,i] 组且异或结果为 x 的最少修改次数，则最终结果为 f(k-1,0)
// 令 x' 为前 i-1 组的异或结果，则前 i 组的异或结果 x=x'^num；若固定 num，则 x' 必须为 x^num；若不固定 num，则 x' 可以为任意值
// 用哈希表统计第 i 组的元素及其次数，若使用哈希表元素 num，则只能从 f(i-1,x^num) 转移，并修改其它元素，f(i,x)=min{ f(i-1,x^num) }+cnt-cnt_num
// 若不使用哈希表中的元素，需要修改该组全部元素，但是可以从任意 x' 转移，f(i,x)=min{ f(i-1,x) }+cnt
// 计算所有 f(i,x) 时，将最小值保存到 g[i] 中，可以在常数时间得到 min{ f(i,x) }=g[i]


class Solution_1787 {
	const int N = 1 << 10; // 数组中元素的上限，0<=nums[i]<=2^10-1，异或结果 x 也在该范围内
public:
	int minChanges(vector<int>& nums, int k) {
		vector<vector<int>> f(k, vector<int>(N, INT_MAX)); // f(i,x) 处理了 [0,i] 组且异或结果为 x 的最少修改次数
		vector<int> g(k, INT_MAX); // 保存所有 x 取值中 f(i,x) 的最小值

		for (int i = 0; i < k; ++i) { // 依次处理每一组
			int cnt = 0; // 记录该组包含的元素个数
			unordered_map<int, int> mp; // 记录该组元素的种类及其出现次数
			for (int j = i; j < nums.size(); j += k) {
				cnt++;
				mp[nums[j]]++;
			}
			if (i == 0) { // 处理第 0 组
				for (int x = 0; x < N; ++x) {
					f[0][x] = cnt - mp[x];
					g[0] = min(g[0], f[0][x]);
				}
			}
			else {
				for (int x = 0; x < N; ++x) {
					f[i][x] = g[i - 1] + cnt; // 不选择哈希表中的数
					for (auto &p : mp) { // 选择哈希表中的数
						f[i][x] = min(f[i][x], f[i - 1][x^p.first] + cnt - p.second);
					}
					g[i] = min(g[i], f[i][x]); // 存储 f(i,x) 的最小值，在下一组的计算中使用
				}
			}
		}
		return f[k - 1][0];
	}
};

void test_1787() {
	vector<int> nums = { 3,4,5,2,1,7,3,4,7 };
	cout << (Solution_1787().minChanges(nums, 3) == 3) << endl;
}