#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_60 {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n + 1, 1); // [1,n] 中 i 个数对应的排列数
		for (int i = 1; i <= n; ++i) {
			nums[i] = nums[i - 1] * i;
		}
		string s; // 保存结果
		vector<bool> used(n + 1, false);   // 记录数字是否被使用过
		while (k > 0) { // 通过计算确定结果的开头，并减小 k 值，在剩下数字中迭代进行
			for (int i = 1; i <= n; ++i) {      // n 为活动数字的个数
				if (nums[i] < k) continue; // 排列数不够，寻找更大的排列数
				// 使用 i 个数字就够了，在 n 个数字中选 n-i 个最小的数字固定在前面
				for (int j = 1; n > i && j < used.size(); ++j) {
					if (!used[j]) { // 使用过的数字不能再次被使用
						used[j] = true;
						s.push_back(j + '0');
						--n;
					}
				}
				// i 个数字恰好形成 k 个排列，按数字大小倒序插入结果
				if (nums[i] == k) {
					for (int j = used.size() - 1; j >= 1; --j) {
						if (!used[j]) s.push_back(j + '0');
					}
					return s;
				}
				// 找出第 k 个排列以哪个数字开头，需要判断 k 是否整除 nums[i-1]
				// 不整除，开头为第 cnt+1 个数；整除，开头为第 cnt 个数
				if (nums[i] > k) {
					int cnt = k / nums[i - 1];
					if (cnt*nums[i - 1] < k) ++cnt;
					int j = 1; // 固定开头为第 cnt 个活动数字
					for (int c = 0; j < used.size(); ++j) {
						if (!used[j]) ++c;
						if (c == cnt) break;
					}
					s.push_back(j + '0');
					used[j] = true;
					--n;
					k -= (cnt - 1)*nums[i - 1];
				}
			}
		}
		return s;
	}
};


class Solution_60_Better {
public:
	string getPermutation(int n, int k) {
		vector<int> factor(n, 1); // 阶乘，排列数
		for (int i = 1; i < n; ++i) {
			factor[i] = factor[i - 1] * i;
		}
		--k; // 使排列编号从零开始，便于计算每个位置上的数字编号
		string ans; // 保存结果
		vector<int> used(n + 1, 1); // 记录数字是否可用

		for (int i = 1; i <= n; ++i) {   // 从前往后确定每一个位置上的数字
			// 前面序列被确定后，位置 i 的每种取值对应 n-i 种排列
			int cnt = k / factor[n - i] + 1;
			for (int j = 1; j <= n; ++j) { // 从小到大找出第 cnt 个可用数字
				cnt -= used[j];      // 只有可用数字才会使 cnt 减一
				if (cnt == 0) {
					used[j] = 0;
					ans.push_back(j + '0');
					break;
				}
			}
			k %= factor[n - i]; // 更新 k 为：在剩余数字的排列集合中的编号
		}
		return ans;
	}
};


void test_60() {
	cout << (Solution_60_Better().getPermutation(4, 9) == "2314") << endl;
}