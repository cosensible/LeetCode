#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


// ��ʼ����Ϊ 0��ÿ����һ��ʯͷ k ���п��ܼ�һ�����һ��ʯͷ���ؼ�һ���� k �����ֵΪ snum-1
// ��ˣ�memo �м�¼ <sid,k> �Ľ�������� sid*snum + k ��Ϊ��
class Solution_403 {
	int snum; // ʯͷ������
	unordered_map<int, int> mp; // ÿ��λ�ö�Ӧ��ʯͷ�ı��
	unordered_map<int, int> memo;
public:
	bool canCross(vector<int>& stones) {
		snum = stones.size();
		for (int i = 0; i < snum; ++i) mp[stones[i]] = i;
		return dfs(stones, 0, 0); // �ӵ� 0 ��ʯͷ��ʼ�����ﲽ��Ϊ 0
	}

private:
	// �Բ��� k �������Ϊ sid ��ʯͷ�������ܷ񵽴����һ��ʯͷ
	bool dfs(vector<int> &stones, int sid, int k) {
		if (sid == snum - 1) return true; // �������һ��ʯͷ
		if (memo.count(sid*snum + k) == 1) return memo[sid*snum + k];
		memo[sid*snum + k] = false; // ��ʼ��
		for (int i = -1; i <= 1; ++i) {
			if (k + i <= 0) continue; // �޷�ǰ��������
			int pos = stones[sid] + k + i;
			if (mp.count(pos) != 0) { // �µ�λ����ʯͷ����������ȥ
				if (dfs(stones, mp[pos], k + i)) {
					memo[sid*snum + k] = true;
					return true;
				}
			}
		}
		return false;
	}
};


class Solution_403_DP {
public:
	bool canCross(vector<int>& stones) {
		int n = stones.size();
		// dp[s][k] �ܷ��Բ��� k ����ʯͷ s
		vector<vector<bool>> dp(n, vector<bool>(n));
		dp[0][0] = true;
		// �����������ڵ�ʯͷ��������ڸ�������󲽳�
		for (int i = 1; i < n; ++i) {
			if (stones[i] - stones[i - 1] > i) {
				return false;
			}
		}
		for (int i = 1; i < n; ++i) { // �������о�ÿ��ʯͷ
			for (int j = i - 1; j >= 0; --j) { // �о�ǰ���ʯͷ
				int k = stones[i] - stones[j]; // ǰһ��ʯͷ����һ��ʯͷ�ľ���
				if (k > j + 1) { // �� j ��ʯͷ�����Ĳ���Ϊ j+1
					break;
				}
				dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
				// �оٵ����һ��ʯͷ�����ҵ����Ե������ʯͷ��ǰһ��ʯͷ
				if (i == n - 1 && dp[i][k]) {
					return true;
				}
			}
		}
		return false;
	}
};


void test_403() {
	vector<int> stones = { 0,1,3,5,6,8,12,17 };
	cout << (Solution_403_DP().canCross(stones) == true) << endl;
}