#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution_554 {
public:
	// 对于每一行，垂线要么穿过砖块，要么穿过缝隙
	// 穿过的砖块数 + 穿过的缝隙数 = 总行数
	// 穿过最少砖块等价于穿过最多缝隙，目标是找出缝隙最多的位置
	int leastBricks(vector<vector<int>>& wall) {
		int rnum = wall.size(); // 总行数
		unordered_map<int, int> mp; // 统计每个位置出现缝隙的次数
		for (auto &row : wall) {
			int idx = 0;
			for (int i = 0; i < row.size() - 1; ++i) {
				idx += row[i];
				mp[idx]++;
			}
		}
		int ans = 0;
		for (auto &p : mp) {
			ans = max(ans, p.second);
		}
		return rnum - ans;
	}
};


void test_554() {
	vector<vector<int>> wall = { {1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1} };
	cout << (Solution_554().leastBricks(wall) == 2) << endl;
}