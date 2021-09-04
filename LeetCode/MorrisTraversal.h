#include "BinaryTree.h"
#include <vector>
using namespace std;

class Morris {
public:
	vector<int> inorder(TreeNode *root) {
		vector<int> ans;
		TreeNode *cur = root, *pre = nullptr;
		while (cur != nullptr) {
			if (cur->left == nullptr) {
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right != nullptr && pre->right != cur) {
					pre = pre->right;
				}
				if (pre->right == nullptr) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					ans.push_back(cur->val);
					pre->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return ans;
	}

	vector<int> preorder(TreeNode *root) {
		vector<int> ans;
		TreeNode *cur = root, *pre = nullptr;
		while (cur) {
			if (cur->left == nullptr) {
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right && pre->right != cur) {
					pre = pre->right;
				}
				if (pre->right==nullptr) {
					pre->right = cur;
					ans.push_back(cur->val);
					cur = cur->left;
				}
				else {
					pre->right = nullptr;
					cur = cur->right;
				}
			}
		}
		return ans;
	}

	vector<int> postorder(TreeNode *root) {
		vector<int> ans;
		TreeNode *dummy = new TreeNode(0, root, nullptr);
		TreeNode *cur = dummy, *pre = nullptr;
		while (cur) {
			if (cur->left == nullptr) {
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right && pre->right != cur) {
					pre = pre->right;
				}
				if (pre->right == nullptr) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = nullptr;
					reversePrint(cur->left, ans);
					cur = cur->right;
				}
			}
		}
		return ans;
	}

	void reverse(TreeNode * &start) {
		TreeNode *p = start, *q = nullptr;
		while (p->right) {
			q = p->right;
			p->right = q->right;
			q->right = start;
			start = q;
		}
	}

	void reversePrint(TreeNode *start, vector<int> &ans) {
		reverse(start);

		for (TreeNode *p = start; p; p = p->right) {
			ans.push_back(p->val);
		}

		reverse(start);
	}
};

void test_morris() {
	vector<const char*> nodes = { "2","1","4","null","null","3","5" };
	TreeNode *tree = arr2Tree(nodes);

	Morris morris;
	auto ans = morris.inorder(tree);
	for (int i : ans) cout << i << " ";
	cout << endl;

	ans = morris.preorder(tree);
	for (int i : ans) cout << i << " ";
	cout << endl;

	ans = morris.postorder(tree);
	for (int i : ans) cout << i << " ";
	cout << endl;
}