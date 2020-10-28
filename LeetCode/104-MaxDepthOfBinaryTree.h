#include "common.h"

using namespace std;

class Solution_104 {
public:
	int maxDepth(TreeNode *root) {
		if (root == nullptr) { return 0; }
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

void test_104() {
	vector<const char*> nv = { "3","9","20","null","null","15","7" };
	cout << "test_104 : " << (Solution_104().maxDepth(arr2Tree(nv)) == 3) << endl;
}