#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// ��������������½��ж�̬�滮����Ҫͬʱ���� "���·����" �� "��С����ʼֵ"�����߶���Ӱ�춯̬�滮���޷�������ȷ��״̬ת��
// ��ˣ������������Ͻ��ж�̬�滮���� f(i,j) Ϊ�� (i,j) ���յ��������С��ʼֵ�����ÿ��Ǵ���㵽 (i,j) ��·����

class Solution_174 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size(), n = dungeon[0].size();
		// ѡ����ұ߻����浽�յ�����Ѫ������Сֵ����ȥ��ǰλ�õ�ֵ�õ� f(i,j)
		// ������ʿ�κ�ʱ��Ѫ����������� 0�����Ҫ�� 1 ȡ���ֵ
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
		dp[m][n - 1] = 1;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};

void test_174() {
	vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
	cout << (Solution_174().calculateMinimumHP(dungeon) == 7) << endl;
}