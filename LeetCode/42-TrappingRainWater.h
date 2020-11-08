#include "common.h"

using namespace std;

class Solution_42_DoublePtr {
public:
	// ���ڵ� i ������, �ܽӵ�����ˮ water[i]=min(lmax[i],rmax[i])-height[i]
	int trap(vector<int>& height) {
		int lmax = 0, rmax = 0, sum = 0;
		for (int l = 0, r = height.size() - 1; l < r;) {
			lmax = max(lmax, height[l]);
			rmax = max(rmax, height[r]);
			if (lmax < rmax) {
				sum += (lmax - height[l++]);
			}
			else {
				sum += (rmax - height[r--]);
			}
		}
		return sum;
	}
};

class Solution_42_Stack {
public:
	int trap(vector<int>& height) {
		int sum = 0;
		stack<int> s;// ����Ƕ�װ��� (()()): [2,0,1,0,2] Ҳ�ܴ���
		for (int i = 0; i < height.size(); ++i) {
			while (!s.empty() && height[i] > height[s.top()]) {
				int mid = s.top();
				s.pop();
				if (s.empty()) { break; }
				int l = s.top(), r = i;
				// ����������ȵ�����, h=0, ��������ˮ
				int h = min(height[l], height[r]) - height[mid];
				int w = r - l - 1;
				sum += h * w;
			}
			s.push(i);
		}
		return sum;
	}
};

void test_42() {
	vector<int> height1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> height2 = { 4,2,0,3,2,5 };
	cout << (Solution_42_DoublePtr().trap(height1) == 6) << endl;
	cout << (Solution_42_Stack().trap(height2) == 9) << endl;
}