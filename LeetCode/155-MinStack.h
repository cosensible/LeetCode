#include <vector>
#include <cstdlib>

using namespace std;

class MinStack {
	vector<int> data;
	int minv = INT_MAX;
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		if (x <= minv) {
			data.push_back(minv);
			data.push_back(x);
			minv = x;
		}
		else data.push_back(x);
	}

	void pop() {
		if (!data.empty()) {
			if (data.back() == minv) {
				data.pop_back();
				minv = data.back();
				data.pop_back();
			}
			else data.pop_back();
		}
	}

	int top() {
		if (!data.empty()) {
			return data.back();
		}
		return minv;
	}

	int getMin() {
		return minv;
	}
};