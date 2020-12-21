#include "common.h"

using namespace std;

class Solution_99 {
public:
	void recoverTree(TreeNode* root) {
		// p ��ǰ�ڵ�  last ��һ���ڵ�
		TreeNode *p = root, *last = nullptr;
		// λ�ô���������ڵ�, n1 ֵ�ϴ�Ľڵ�, n2 ֵ��С�Ľڵ�
		TreeNode *n1 = nullptr, *n2 = nullptr;
		stack<TreeNode*> s;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			// ����������̳����½�, ��λ�ô���Ľڵ�
			// ֵ�ϴ�Ľڵ����׸��½�λ��, ֵ��С�Ľڵ�������½�λ��
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

void test_99() {
	vector<const char*> v1 = { "3","1","4","null","null","2" };
	vector<const char*> v2 = { "2","1","4","null","null","3" };
	TreeNode *root = arr2Tree(v1), *expt = arr2Tree(v2);
	Solution_99().recoverTree(root);
	cout << isTreeSame(root, expt) << endl;
}