#include "common.h"
using namespace std;

class Solution_156 {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		// ��Ϊ�ջ�Ҷ�ڵ㣬���跭ת
		if (!root || !root->left && !root->right) return root;
		// ������ҪôΪ��ҪôΪҶ�ڵ㣬��ת��ֻ����Ϊ��Ҷ�ڵ㣬���ֻ�����������
		// �ݹ��������������ת���ĸ��ڵ�����������
		TreeNode *newRoot = upsideDownBinaryTree(root->left);
		// ÿ�εݹ����������غ󣬸��ڵ�����Ҷ��ӻ�δ���ı䣬�����ø��ӹ�ϵ���ϲ�ڵ㷭ת
		root->left->left = root->right;
		root->left->right = root;
		root->left = root->right = nullptr;
		return newRoot;
	}
};


void test_156() {
	vector<const char*> v = { "1","2","3","4","5" };
	TreeNode *tree = arr2Tree(v);
	TreeNode *ans = Solution_156().upsideDownBinaryTree(tree);
	printTree(ans);
}