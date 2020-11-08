#include <string>
#include <sstream>

#include "BinaryTree.h"
#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(const string &data) {
		istringstream in(data);
		return deserialize(in);
	}

private:
	void serialize(TreeNode *root, ostringstream &out) {
		if (root) {
			out << root->val << " ";
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else { out << "# "; }
	}

	TreeNode* deserialize(istringstream &in) {
		string val;
		in >> val;
		if (val == "#") { return nullptr; }
		TreeNode *root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

void test_297() {
	vector<const char*> nv = { "1","2","3","null","null","4","5" };
	TreeNode *tree = arr2Tree(nv);
	Codec codec;
	TreeNode *res = codec.deserialize(codec.serialize(tree));
	cout << isTreeSame(tree, res) << endl;
}