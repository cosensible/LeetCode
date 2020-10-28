#include "BinaryTree.h"
#include <queue>
#include <vector>

using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself.
*/

class Solution_101 {
public:
	// µÝ¹é·¨
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) { return true; }
		return treeSym(root->left, root->right);
	}
	bool treeSym(TreeNode *t1, TreeNode *t2) {
		if (bool(t1) ^ bool(t2)) { return false; }
		if (!t1) { return true; }
		if (t1->val != t2->val) { return false; }
		return treeSym(t1->left, t2->right) && treeSym(t1->right, t2->left);
	}

	//// µü´ú·¨
	//bool isSymmetric(TreeNode* root) {
	//	if (root == nullptr) { return true; }
	//	queue<TreeNode*> qtp1, qtp2;
	//	qtp1.push(root->left), qtp2.push(root->right);
	//	while (!qtp1.empty()) {
	//		if (qtp2.empty()) { return false; }
	//		TreeNode *t1 = qtp1.front(), *t2 = qtp2.front();
	//		if (bool(t1) ^ bool(t2)) { return false; }
	//		if (!t1) {
	//			qtp1.pop(), qtp2.pop();
	//			continue;
	//		}
	//		if (t1->val != t2->val) { return false; }
	//		qtp1.push(t1->left), qtp1.push(t1->right);
	//		qtp2.push(t2->right), qtp2.push(t2->left);
	//		qtp1.pop(), qtp2.pop();
	//	}
	//	return true;
	//}
};

void test_101() {
	vector<const char*> nv1 = { "1","2","2","3","4","4","3" };
	vector<const char*> nv2 = { "1","2","2","null","3","null","3" };
	TreeNode *t1 = arr2Tree(nv1), *t2 = arr2Tree(nv2);
	Solution_101 s;
	cout << "test_101 : " << (s.isSymmetric(t1) && !s.isSymmetric(t2)) << endl;
}