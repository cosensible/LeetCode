#include "common.h"

using namespace std;

class Solution_124 {
	int maxSum = INT_MIN;
public:
	// �·������������ɣ������� + ���� + ���½�
	// ��ÿ���ڵ���Ϊ���������·�������ֵ
	// ��Ҫ��������������½����ֵĳ���
	int maxPathSum(TreeNode* root) {
		if (root == nullptr) { return 0; }
		helper(root);
		return maxSum;
	}

private:
	// ���ش� root �ڵ��������ܹ���õ��·��
	int helper(TreeNode *root) {
		if (root == nullptr) { return 0; }
		// ���������, �����Ҷ� <0, ����������
		// �ݹ�����������������ߵ��·��
		int lsum = max(helper(root->left), 0);
		int rsum = max(helper(root->right), 0);
		// ��ÿ���ڵ���Ϊ�����ܹ��������·��
		maxSum = max(maxSum, lsum + rsum + root->val);
		return root->val + max(lsum, rsum);
	}
};

void test_124() {
	vector<const char*> nodes = { "-10","9","20","null","null","15","7" };
	TreeNode *tree = arr2Tree(nodes);
	cout << (Solution_124().maxPathSum(tree) == 42) << endl;
}