// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution_116 {
public:
	Node* connect(Node* root) {
		// root为空或为叶节点, 直接返回
		if (root == nullptr || root->left == nullptr&&root->right == nullptr) return root;
		Node *p1 = root, *p2 = nullptr; // 两个行指针, p1为p2的父节点
		Node *pleft = root; // 保存每行的起点, 在p1到达行尾时使其指向下一行的起点
		while (p1) {
			p2 = p1->left;
			p2->next = p1->right;
			p2 = p2->next;
			if (p1->next) {
				p2->next = p1->next->left;
				p1 = p1->next;
			}
			else {
				p1 = pleft->left;
				pleft = p1;
				// p1为叶节点, 没有下一行, 结束
				if (p1->left == nullptr) break;
			}
		}
		return root;
	}
};

class Solution_116_2 {
public:
	Node* connect(Node* root) {
		if (root == nullptr) { return root; }

		// 从根节点开始
		Node* leftmost = root;
		while (leftmost->left != nullptr) {
			// 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
			Node* head = leftmost;
			while (head != nullptr) {
				// CONNECTION 1
				head->left->next = head->right;
				// CONNECTION 2
				if (head->next != nullptr) {
					head->right->next = head->next->left;
				}
				// 指针向后移动
				head = head->next;
			}
			// 去下一层的最左的节点
			leftmost = leftmost->left;
		}

		return root;
	}
};