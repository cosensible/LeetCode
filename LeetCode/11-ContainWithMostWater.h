#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_11 {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int area = (j - i)*min(height[i], height[j]);
		int res = area;
		while (i != j) {
			if (height[i] < height[j])++i;
			else --j;
			area = (j - i)*min(height[i], height[j]);
			if (area > res)res = area;
		}
		return res;
	}
};

void test_11() {
	vector<int> vi = { 1,8,6,2,5,4,8,3,7 };
	cout << (Solution_11().maxArea(vi) == 49) << endl;
}