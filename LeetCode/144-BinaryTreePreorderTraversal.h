#include "BinaryTree.h"
#include <vector>
#include <stack>

using namespace std;

class Solution_144 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		TreeNode *p = root;
		stack<TreeNode*> ps;
		vector<int> res;
		while (p != nullptr || !ps.empty()) {
			if (p != nullptr) { //打印节点值,记录该节点,并遍历左子树
				res.push_back(p->val);
				ps.push(p);
				p = p->left;
			}
			else { //左子树遍历完,遍历右子树
				p = ps.top()->right;
				ps.pop();
			}
		}
		return res;
	}
};

void test_144() {
	vector<const char*> nv = { "1","null","2","null","null","3","null" };
	vector<int> res = Solution_144().preorderTraversal(arr2Tree(nv));
	vector<int> exp = { 1,2,3 };
	auto comp = [](const vector<int> &nums1, const vector<int> &nums2) {
		if (nums1.size() != nums2.size()) return false;
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] != nums2[i]) return false;
		}
		return true;
	};
	cout << comp(exp, res) << endl;
}