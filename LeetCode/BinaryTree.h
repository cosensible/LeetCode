#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 数组转化为满二叉树
TreeNode* arr2Tree(const std::vector<const char*> &arr) {
	if (arr.size() == 0) { return nullptr; }
	// 指针数组，指针指向 NULL 或 TreeNode
	std::vector<TreeNode*> treeNodePtrs(arr.size(), nullptr);
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] != "null") {
			treeNodePtrs[i] = new TreeNode(atoi(arr[i]));
		}
	}
	// 满二叉树中，左儿子的索引为 2*i+1，右儿子为 2*i+2，i 从零开始
	for (int i = 0; i < arr.size(); ++i) {
		if (treeNodePtrs[i] != nullptr) {
			if (2 * i + 1 < arr.size()) {
				treeNodePtrs[i]->left = treeNodePtrs[2 * i + 1];
			}
			if (2 * i + 2 < arr.size()) {
				treeNodePtrs[i]->right = treeNodePtrs[2 * i + 2];
			}
		}
	}
	return treeNodePtrs[0];
}

// 层序遍历打印
void printTree(TreeNode *root) {
	if (root == nullptr) { return; }
	std::vector<TreeNode*> nodeList = { root };
	while (!nodeList.empty()) {
		std::vector<TreeNode*> nextNodeList; // 保存下一层节点
		for (int i = 0; i < nodeList.size(); ++i) {
			if (nodeList[i] == nullptr) { std::cout << "N" << " "; }
			else {
				std::cout << nodeList[i]->val << " ";
				nextNodeList.push_back(nodeList[i]->left);
				nextNodeList.push_back(nodeList[i]->right);
			}
		}
		std::cout << std::endl;
		std::swap(nodeList, nextNodeList);
	}
}

int maxDepth(TreeNode *root) {
	if (root == nullptr) { return 0; }
	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isTreeSame(TreeNode *t1, TreeNode *t2) {
	if (t1 == nullptr && t2 == nullptr) { return true; }
	if (t1 != nullptr && t2 != nullptr && t1->val == t2->val) {
		return isTreeSame(t1->left, t2->left) && isTreeSame(t1->right, t2->right);
	}
	return false;
}

void printTreeGraph(TreeNode *tree)
{
	if (tree != nullptr) {
		std::cout << std::setw(4 * maxDepth(tree)) << ' ';
		std::cout << tree->val << std::endl;
		if (tree->left) printTreeGraph(tree->left);
		if (tree->right) printTreeGraph(tree->right);
	}
}

void testBinaryTree() {
	std::vector<const char*> nv1 = { "3","9","20","1","null","15","7" };
	std::vector<const char*> nv2 = { "3","9","20","1","null","15","7" };
	TreeNode *t1 = arr2Tree(nv1), *t2 = arr2Tree(nv2);
	if (isTreeSame(t1, t2)) { std::cout << "t1 == t2" << std::endl; }
	else { std::cout << "t1 != t2" << std::endl; }
}

#endif // !BINARY_TREE_H