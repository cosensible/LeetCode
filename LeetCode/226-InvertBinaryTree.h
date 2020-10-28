#include "common.h"

using namespace std;

class Solution_226 {
public:
	TreeNode* invertTree(TreeNode *root) {
		if (root == nullptr) { return nullptr; }
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		return root;
	}
};

void test_226() {
	vector<const char*> nvOld = { "3","9","20","null","null","15","7" };
	vector<const char*> nvNew = { "3","20","9","7","15" };
	TreeNode *oldTree = arr2Tree(nvOld), *newTree = arr2Tree(nvNew);

	TreeNode *invTree = Solution_226().invertTree(oldTree);
	cout << "test_226 : " << isTreeSame(newTree, invTree) << endl;
}