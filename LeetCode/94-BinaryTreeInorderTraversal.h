#include "BinaryTree.h"
#include <vector>
#include <stack>

using namespace std;

class Solution_94 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode *p = root;
		stack<TreeNode*> ps;
		vector<int> res;
		while (p != nullptr || !ps.empty()) {
			if (p != nullptr) { //��¼�ýڵ�,������������
				ps.push(p);
				p = p->left;
			}
			else { //������������,��ӡ���ڵ�ֵ,������������
				p = ps.top();
				ps.pop();
				res.push_back(p->val);
				p = p->right;
			}
		}
		return res;
	}
};

void test_94() {
	vector<const char*> nv = { "1","null","2","null","null","3","null" };
	vector<int> res = Solution_94().inorderTraversal(arr2Tree(nv));
	vector<int> exp = { 1,3,2 };
	auto comp = [](const vector<int> &nums1, const vector<int> &nums2) {
		if (nums1.size() != nums2.size()) return false;
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] != nums2[i]) return false;
		}
		return true;
	};
	cout << comp(exp, res) << endl;
}