#include "common.h"
using namespace std;

class Solution_199 {
	vector<int> leftRes, rightRes;
public:
	vector<int> leftSideView(TreeNode *root) {
		//leftDFS(root, 0);
		//return leftRes;

		if (root == nullptr) return {};
		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			bool flag = false;
			for (int i = 0; i < n; ++i) {
				if (q.front() != nullptr) {
					if (!flag) {
						flag = true;
						res.push_back(q.front()->val);
					}
					q.push(q.front()->left);
					q.push(q.front()->right);
				}
				q.pop();
			}
		}
		return res;
	}

	vector<int> rightSideView(TreeNode* root) {
		rightDFS(root, 0);
		return rightRes;
	}

private:
	void leftDFS(TreeNode *root, int depth) {
		if (root == nullptr) { return; }
		if (depth == leftRes.size()) {
			leftRes.push_back(root->val);
		}
		leftDFS(root->left, 1 + depth);
		leftDFS(root->right, 1 + depth);
	}

	void rightDFS(TreeNode *root, int depth) {
		if (root == nullptr) { return; }
		if (depth == rightRes.size()) {
			rightRes.push_back(root->val);
		}
		rightDFS(root->right, 1 + depth);
		rightDFS(root->left, 1 + depth);
	}
};


void test_199() {
	std::vector<const char*> v = { "3","9","20","null","null","15","null" };
	TreeNode *root = arr2Tree(v);
	auto leftView = Solution_199().leftSideView(root);
	auto rightView = Solution_199().rightSideView(root);

	cout << "left view: ";
	for (int i : leftView) {
		cout << i << ",";
	}
	cout << endl;

	cout << "right view: ";
	for (int i : rightView) {
		cout << i << ",";
	}
	cout << endl;
}