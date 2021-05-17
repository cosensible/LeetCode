#include "common.h"
using namespace std;

class Solution_993_DFS {
	int kx = -1, ky = -1; // x��y �����
	TreeNode *fx = nullptr, *fy = nullptr; // x��y �ĸ��ڵ�
public:
	bool isCousins(TreeNode* root, int x, int y) {
		dfs(root, nullptr, x, y, 0);
		// �����ͬ�Ҹ��ڵ㲻ͬ����������
		if (kx == ky && fx != fy) return true;
		return false;
	}

private:
	void dfs(TreeNode *root, TreeNode *parent, int x, int y, int k) {
		if (root == nullptr) return;
		if (kx != -1 && ky != -1) return; // �����ڵ㶼���ҵ��������ٲ���
		if (root->val == x) { // �ҵ� x�������������ң���Ϊ���ֵ���ͬһ��
			kx = k;
			fx = parent;
			return;
		}
		if (root->val == y) {
			ky = k;
			fy = parent;
			return;
		}
		dfs(root->left, root, x, y, k + 1);
		dfs(root->right, root, x, y, k + 1);
	}
};


struct Triple {
	int k;
	TreeNode *cur;
	TreeNode *parent;
	Triple(int k_, TreeNode *node, TreeNode *p) :k(k_), cur(node), parent(p) {}
};

class Solution_993_BFS {
	int kx = -1, ky = -1;
	TreeNode *fx = nullptr, *fy = nullptr;
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root) return false;
		queue<Triple> q;
		q.push({ 0,root,nullptr });
		while (!q.empty()) {
			Triple node = q.front();
			q.pop();
			if (node.cur->val == x) {
				kx = node.k;
				fx = node.parent;
			}
			else if (node.cur->val == y) {
				ky = node.k;
				fy = node.parent;
			}
			else {
				if (node.cur->left) q.push({ node.k + 1, node.cur->left,node.cur });
				if (node.cur->right) q.push({ node.k + 1, node.cur->right,node.cur });
			}
			if (kx != -1 && ky != -1) break;
		}
		return kx == ky && fx != fy;
	}
};


void test_993() {
	vector<const char*> v = { "1","2","3","null","4","null","5" };
	TreeNode *tree = arr2Tree(v);
	cout << (Solution_993_DFS().isCousins(tree, 5, 4) == true && Solution_993_BFS().isCousins(tree, 2, 3) == false) << endl;
}