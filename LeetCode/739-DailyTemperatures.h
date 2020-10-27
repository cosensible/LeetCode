#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution_739 {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> res(n);

		//stack<int> ts;
		//for (int i = n - 1; i >= 0; --i) {
		//	while (!ts.empty() && T[i] >= T[ts.top()]) ts.pop();
		//	if (ts.empty()) res[i] = 0;
		//	else res[i] = ts.top() - i;
		//	ts.push(i);
		//}
		//return res;

		vector<int> lastpos(101, n);
		for (int i = n - 1; i >= 0; --i) {
			int wi = n;
			for (int j = T[i] + 1; j <= 100; ++j) {
				if (lastpos[j] < wi) wi = lastpos[j];
			}
			if (wi < n) res[i] = wi - i;
			lastpos[T[i]] = i;
		}
		return res;
	}
};

//class Solution {
//public:
//	vector<int> dailyTemperatures(vector<int>& temperatures) {
//		int n = temperatures.size();
//		vector<int> res(n, 0);
//		stack<int> st;
//		for (int i = 0; i < temperatures.size(); ++i) {
//			while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
//				auto t = st.top(); st.pop();
//				res[t] = i - t;
//			}
//			st.push(i);
//		}
//		return res;
//	}
//};

void test_739() {
	vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> res = Solution_739().dailyTemperatures(T);
	vector<int> exp = { 1, 1, 4, 2, 1, 1, 0, 0 };

	auto comp = [](const vector<int> &nums1, const vector<int> &nums2) {
		if (nums1.size() != nums2.size()) return false;
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] != nums2[i]) return false;
		}
		return true;
	};
	cout << comp(res, exp) << endl;
}