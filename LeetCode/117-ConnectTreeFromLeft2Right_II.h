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

class Solution_117 {
public:
	// 树的每一层相当于一个链表, 通过上层链表构造下层链表
	// 由于下层链表的头部难以确定, 在构造下层链表时需要一个哑节点
	Node* connect(Node* root) {
		if (root == nullptr) return root;
		Node *head = root; // 遍历上层链表的指针
		Node *dummy = new Node(); // 构造下层链表的哑节点

		while (head) {
			// 遍历上层链表, 并构造下层链表
			Node *p2 = dummy;
			while (head) {
				if (head->left) { // 左儿子不为空, 在下一层添加左儿子
					p2->next = head->left;
					p2 = p2->next;
				}
				if (head->right) { // 右儿子不为空, 在下一层添加右儿子
					p2->next = head->right;
					p2 = p2->next;
				}
				head = head->next;
			}
			// 当前层构造完毕, 开始下一层构造
			head = dummy->next;
			dummy->next = nullptr;
		}

		return root;
	}
};