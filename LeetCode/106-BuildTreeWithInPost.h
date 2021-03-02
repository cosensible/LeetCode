#include "common.h"
using namespace std;

class Solution_106 {
	int postIdx;
	unordered_map<int, int> mp;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		postIdx = postorder.size() - 1;
		// ����ڵ���������������е����������ڽ������ָ�Ϊ��������
		for (int i = 0; i < inorder.size(); ++i) {
			mp[inorder[i]] = i;
		}
		return helper(inorder, postorder, 0, inorder.size() - 1);
	}

	TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int l, int r) {
		if (l > r) return nullptr;
		// �ȹ�����ڵ�, �ٹ�����������������, ����������˳���෴, ���� postIdx ���Եݼ�
		int val = postorder[postIdx--];
		TreeNode *root = new TreeNode(val);
		root->right = helper(inorder, postorder, mp[val] + 1, r);
		root->left = helper(inorder, postorder, l, mp[val] - 1);
		return root;
	}
};

void test_106() {
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	TreeNode *tree = Solution_106().buildTree(inorder, postorder);
	printTree(tree);
}