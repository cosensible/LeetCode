#include "common.h"
using namespace std;

class Solution_872 {
public:
	// 两棵树同步遍历叶子节点，如果叶子节点不相等，提前返回
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		stack<TreeNode*> s1, s2;
		TreeNode *p1 = root1, *p2 = root2;
		if (root1) s1.push(root1);
		if (root2) s2.push(root2);
		// 两棵树都还有叶子节点，需要继续遍历
		while (!s1.empty() && !s2.empty()) {
			p1 = s1.top(); s1.pop();
			p2 = s2.top(); s2.pop();
			// 遍历第一棵树，直至遇到其叶子节点
			while (p1->left || p1->right) {
				if (p1->left) { // 先遍历左子树，并保存下一次搜寻叶子节点的起点
					if (p1->right) s1.push(p1->right);
					p1 = p1->left;
				}
				else { // 左子树为空，直接遍历右子树
					p1 = p1->right;
				}
			}
			// 遍历第二棵树，直至遇到其叶子节点
			while (p2->left || p2->right) {
				if (p2->left) {
					if (p2->right) s2.push(p2->right);
					p2 = p2->left;
				}
				else {
					p2 = p2->right;
				}
			}
			// 两棵树的当前叶子节点不相等，提前返回
			if (p1->val != p2->val) return false;
		}
		// 两棵树的叶子节点都被遍历完，返回 true
		return s1.empty() && s2.empty();
	}
};


class Solution_872_Recursion {
public:
	// 先序遍历并保存叶子节点到数组中，最后比较数组是否相同
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> leaves1, leaves2;
		getLeaves(root1, leaves1);
		getLeaves(root2, leaves2);
		if (leaves1.size() != leaves2.size()) return false;
		for (int i = 0; i < leaves1.size(); ++i) {
			if (leaves1[i] != leaves2[i]) return false;
		}
		return true;
	}

	void getLeaves(TreeNode *root, vector<int> &leaves) {
		if (root == nullptr) return;
		if (root->left == nullptr&&root->right == nullptr) {
			leaves.push_back(root->val);
			return;
		}
		getLeaves(root->left, leaves);
		getLeaves(root->right, leaves);
	}
};


void test_872() {
	//vector<const char*> v1 = { "3","5","1","6","2","9","8","null","null","7","4" };
	//vector<const char*> v2 = { "3","5", "1", "6", "7", "4", "2", "null", "null", "null", "null", "null", "null", "9", "8" };
	vector<const char*> v1 = { "1","2","3" };
	vector<const char*> v2 = { "1","3","2" };
	TreeNode *tree1 = arr2Tree(v1), *tree2 = arr2Tree(v2);
	cout << (Solution_872().leafSimilar(tree1, tree2) == false) << endl;
}