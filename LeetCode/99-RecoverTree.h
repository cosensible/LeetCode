#include "common.h"

using namespace std;

class Solution_99 {
public:
	void recoverTree(TreeNode* root) {
		// p 当前节点  last 上一个节点
		TreeNode *p = root, *last = nullptr;
		// 位置错误的两个节点, n1 值较大的节点, n2 值较小的节点
		TreeNode *n1 = nullptr, *n2 = nullptr;
		stack<TreeNode*> s;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			// 中序遍历过程出现下降, 有位置错误的节点
			// 值较大的节点在首个下降位置, 值较小的节点在最后下降位置
			if (last && last->val > p->val) {
				if (!n1) { n1 = last; }
				n2 = p;
			}
			last = p;
			p = p->right;
			s.pop();
		}
		swap(n1->val, n2->val);
	}
};

class Solution_99_Morris {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *cur = root, *last = nullptr;
		TreeNode *n1 = nullptr, *n2 = nullptr;
		while (cur) {
			if (cur->left) {
				// 找 cur 节点的前驱节点
				TreeNode *pre = cur->left;
				while (pre->right && pre->right != cur) { pre = pre->right; }
				// 通过前驱节点回到 cur 节点, 处理 cur 节点并还原二叉树, 继续遍历右子树
				if (pre->right == cur) {
					if (last && last->val > cur->val) {
						if (!n1) { n1 = last; }
						n2 = cur;
					}
					pre->right = nullptr;
					last = cur;
					cur = cur->right;
				}
				// 与前驱节点建立联系, 以便快速回到 cur 节点
				else {
					pre->right = cur;
					cur = cur->left;
				}
			}
			else {
				if (last && last->val > cur->val) {
					if (!n1) { n1 = last; }
					n2 = cur;
				}
				last = cur;
				cur = cur->right;
			}
		}
		swap(n1->val, n2->val);
	}
};

void test_99() {
	vector<const char*> v1 = { "3","1","4","null","null","2" };
	vector<const char*> v2 = { "2","1","4","null","null","3" };
	TreeNode *root = arr2Tree(v1), *expt = arr2Tree(v2);
	//Solution_99().recoverTree(root);
	Solution_99_Morris().recoverTree(root);
	cout << isTreeSame(root, expt) << endl;
}