#include "BinaryTree.h"
#include <vector>
#include <stack>

using namespace std;

class Solution_145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode *p = root, *lastTravel = nullptr;
		stack<TreeNode*> ps;
		vector<int> res;
		while (p != nullptr || !ps.empty()) {
			if (p != nullptr) { //一直遍历左子树
				ps.push(p);
				p = p->left;
			}
			else { //左子树为空,遍历右子树
				p = ps.top()->right;
				if (p == nullptr || p == lastTravel) {
					//右子树遍历完,打印根节点值并更新lastTravel,再回到上一层
					lastTravel = ps.top();
					res.push_back(lastTravel->val);
					ps.pop();
					p = nullptr;
				}
			}
		}
		return res;
	}
};

void test_145() {
	vector<const char*> nv = { "1","null","2","null","null","3","null" };
	vector<int> res = Solution_145().postorderTraversal(arr2Tree(nv));
	vector<int> exp = { 3,2,1 };
	auto comp = [](const vector<int> &nums1, const vector<int> &nums2) {
		if (nums1.size() != nums2.size()) return false;
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] != nums2[i]) return false;
		}
		return true;
	};
	cout << comp(exp, res) << endl;
}