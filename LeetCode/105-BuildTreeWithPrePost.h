#include "common.h"
using namespace std;

class Solution_105 {
	int preIdx = 0;
	unordered_map<int, int> mp;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int m = preorder.size(), n = inorder.size();
		if (m != n || n == 0) return nullptr;
		// ����ڵ���������������е����������ڽ������ָ�Ϊ��������
		for (int i = 0; i < n; ++i) {
			mp[inorder[i]] = i;
		}
		return helper(preorder, inorder, 0, n - 1);
	}

	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l, int r) {
		if (l > r) return nullptr;
		// �ȹ�����ڵ�, �ٹ�����������������, ��ǰ�������˳��һ��, ���� preIdx ���Ե���
		int val = preorder[preIdx++];
		TreeNode *root = new TreeNode(val);
		root->left = helper(preorder, inorder, l, mp[val] - 1);
		root->right = helper(preorder, inorder, mp[val] + 1, r);
		return root;
	}
};

void test_105() {
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode *tree = Solution_105().buildTree(preorder, inorder);
	printTree(tree);
}