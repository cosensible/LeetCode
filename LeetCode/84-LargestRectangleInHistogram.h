#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

/* https://leetcode.com/problems/largest-rectangle-in-histogram/ */

class Solution_84 {
public:
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

void test_84() {
	vector<int> heights = { 2,1,5,6,2,3 };
	cout << (Solution_84().largestRectangleArea(heights) == 10) << endl;
}