#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution_554 {
public:
	// ����ÿһ�У�����Ҫô����ש�飬Ҫô������϶
	// ������ש���� + �����ķ�϶�� = ������
	// ��������ש��ȼ��ڴ�������϶��Ŀ�����ҳ���϶����λ��
	int leastBricks(vector<vector<int>>& wall) {
		int rnum = wall.size(); // ������
		unordered_map<int, int> mp; // ͳ��ÿ��λ�ó��ַ�϶�Ĵ���
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