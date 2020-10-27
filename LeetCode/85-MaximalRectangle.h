#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

/* https://leetcode.com/problems/maximal-rectangle/ */

class Solution_85 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = 0, maxarea = 0;
		if (m > 0) n = matrix[0].size();

		vector<int> dp(n, 0);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') dp[j] = 0;
				else dp[j] += 1;
			}
			maxarea = max(maxarea, largestRectangleArea(dp));
		}
		return maxarea;
	}

private:
	int largestRectangleArea(vector<int>& heights) {
		//以各个条形为最低高度得到所有矩形
		//最大矩形为所有矩形中的最大值
		int area = 0;
		stack<int> st;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i) {
			while (!st.empty() && heights[st.top()] > heights[i]) {
				int height = heights[st.top()];
				st.pop();
				area = max(area, height*(st.empty() ? i : i - st.top() - 1));
			}
			st.push(i);
		}
		return area;
	}
};

void test_85() {
	vector<vector<char>> matrix = {
		{'1','0','1','0','0' },
		{'1','0','1','1','1' },
		{'1','1','1','1','1' },
		{'1','0','0','1','0' } };
	cout << (Solution_85().maximalRectangle(matrix) == 6) << endl;
}