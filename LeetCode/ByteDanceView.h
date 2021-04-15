#include <queue>
#include <vector>
#include <iostream>
using namespace std;


vector<double> getMedium(const vector<int> &nums) {
	priority_queue<int> maxQue;
	priority_queue<int, vector<int>, greater<int>> minQue;


	vector<double> res(nums.size());
	for (int i = 0; i < nums.size(); ++i) {
		if (minQue.size() == maxQue.size()) {
			maxQue.push(nums[i]);
			minQue.push(maxQue.top());
			maxQue.pop();
			res[i] = minQue.top();
		}
		else {
			minQue.push(nums[i]);
			maxQue.push(minQue.top());
			minQue.pop();
			res[i] = (minQue.top() + maxQue.top()) / 2.0;
		}
	}
	return res;
}


void test_ByteDance() {
	vector<int> nums = { 3,8,9,2,0,5,7 };
	vector<double> res = getMedium(nums);
	for (double i : res) {
		cout << i << ", ";
	}
	cout << endl;
}