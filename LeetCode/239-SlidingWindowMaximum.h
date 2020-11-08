#include "common.h"

using namespace std;

class Solution_239 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (k <= 0) return res;
		if (k == 1) return nums;

		deque<int> dq;
		for (int r = 0; r < nums.size(); ++r) {
			if (r >= k) {
				res.push_back(nums[dq.front()]);
				if (dq.front() < r - k + 1) dq.pop_front();
			}
			while (!dq.empty() && nums[r] > nums[dq.back()]) {
				dq.pop_back();
			}
			dq.push_back(r);
		}
		if (!dq.empty())
			res.push_back(nums[dq.front()]);
		return res;
	}
};

class DescQue {
	deque<int> dq;
public:
	void push(int val) {
		while (!dq.empty() && val > dq.back())
			dq.pop_back();
		dq.push_back(val);
	}
	int pop(int val) {
		if (!dq.empty() && val == dq.front())
			dq.pop_front();
		return val;
	}
	int front() {
		return dq.front();
	}
	bool empty() {
		return dq.empty();
	}
};

class Solution_DESCQUE {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (k <= 0) return res;
		if (k == 1) return nums;

		DescQue descq;
		for (int r = 0; r < nums.size(); ++r) {
			if (r >= k) {
				res.push_back(descq.front());
				descq.pop(nums[r - k]);
			}
			descq.push(nums[r]);
		}
		if (!descq.empty())
			res.push_back(descq.front());
		return res;
	}
};

void test_239() {
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;

	vector<int> res = Solution_DESCQUE().maxSlidingWindow(nums, k);
	for (auto num : res) {
		cout << num << ",";
	}
	cout << endl;
}