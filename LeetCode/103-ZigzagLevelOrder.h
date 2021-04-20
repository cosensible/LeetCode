#include "common.h"
using namespace std;


// �������ұ���level���ͬʱ, �������ұ�����һ��ڵ�, ����ջ�ṹ, �Ա��ӡ��һ��ʱ�ܹ���������
// ͬ��, �����������level���ͬʱ, ��Ҫ�������󱣴���һ��ڵ�
class Solution_103 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		stack<TreeNode*> s;
		s.push(root);
		for (int level = 1; !s.empty(); ++level) {
			stack<TreeNode*> s1; // ��һ��������ڵ�
			vector<int> nodes;   // ����ò�������
			while (!s.empty()) {
				TreeNode *p = s.top(); s.pop();
				nodes.push_back(p->val);
				if (level & 1) {
					if (p->left) s1.push(p->left);
					if (p->right) s1.push(p->right);
				}
				else {
					if (p->right) s1.push(p->right);
					if (p->left) s1.push(p->left);
				}
			}
			res.push_back(std::move(nodes));
			swap(s, s1);
		}
		return res;
	}

	void printTreeInZigzag(TreeNode *root) {
		if (root == nullptr) return;
		stack<TreeNode*> stk;
		stk.push(root);
		bool flag = true;
		while (!stk.empty()) {
			stack<TreeNode*> stk1;
			while (!stk.empty()) {
				TreeNode *p = stk.top();
				cout << p->val << " ";
				stk.pop();
				if (flag) {
					if (p->left) stk1.push(p->left);
					if (p->right) stk1.push(p->right);
				}
				else {
					if (p->right) stk1.push(p->right);
					if (p->left) stk1.push(p->left);
				}
			}
			flag = !flag;
			swap(stk, stk1);
			cout << endl;
		}
	}
};

void test_103() {
	vector<const char*> vs = { "3","9","20","null","null","15","7" };
	TreeNode *root = arr2Tree(vs);
	Solution_103().printTreeInZigzag(root);

	//auto res = Solution_103().zigzagLevelOrder(root);
	//for (auto &v : res) {
	//	for (int i : v) {
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//}
}