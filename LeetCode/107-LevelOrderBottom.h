#include "common.h"
using namespace std;

class Solution_107 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;
		vector<TreeNode*> v1 = { root };
		while (!v1.empty()) {
			vector<TreeNode*> v2; // ������һ��ڵ�
			res.emplace_back();   // ���浱ǰ��Ľڵ�ֵ
			for (auto ptr : v1) {
				if (ptr->left) v2.push_back(ptr->left);
				if (ptr->right) v2.push_back(ptr->right);
				res.back().push_back(ptr->val);
			}
			swap(v1, v2);
		}
		reverse(res.begin(), res.end()); // ��ת���, �õ��Ե����ϵĲ���������
		return res;
	}
};

void test_107() {
	vector<const char*> vs = { "3","9","20","null","null","15","7" };
	TreeNode *tree = arr2Tree(vs);
	auto res = Solution_107().levelOrderBottom(tree);
	for (auto &v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}