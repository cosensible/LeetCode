#include "common.h"
using namespace std;

class Solution_129 {
	int res = 0; // ��������֮��
	int num = 0; // ���浱ǰ����
public:
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) return 0;
		// ����ǰ�ڵ�
		num = num * 10 + root->val;
		// �����ǰ�ڵ�ΪҶ�ڵ�, �ۼ�res, ��ԭnum, ��������һ��
		if (root->left == nullptr&&root->right == nullptr) {
			res += num;
			num /= 10;
			return res;
		}
		// ����Ҷ�ڵ�, �ݹ鴦����������������
		if (root->left) sumNumbers(root->left);
		if (root->right) sumNumbers(root->right);
		num /= 10; // ���Ҷ��Ӷ���������, ������һ�㴦��
		return res;
	}
};

void test_129() {
	vector<const char*> vi = { "4","9","0","5","1" };
	TreeNode *tree = arr2Tree(vi);
	cout << (Solution_129().sumNumbers(tree) == 1026) << endl;
}