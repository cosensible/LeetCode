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
		// rootΪ�ջ�ΪҶ�ڵ�, ֱ�ӷ���
		if (root == nullptr || root->left == nullptr&&root->right == nullptr) return root;
		Node *p1 = root, *p2 = nullptr; // ������ָ��, p1Ϊp2�ĸ��ڵ�
		Node *pleft = root; // ����ÿ�е����, ��p1������βʱʹ��ָ����һ�е����
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
				// p1ΪҶ�ڵ�, û����һ��, ����
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

		// �Ӹ��ڵ㿪ʼ
		Node* leftmost = root;
		while (leftmost->left != nullptr) {
			// ������һ��ڵ���֯�ɵ�����Ϊ��һ��Ľڵ���� next ָ��
			Node* head = leftmost;
			while (head != nullptr) {
				// CONNECTION 1
				head->left->next = head->right;
				// CONNECTION 2
				if (head->next != nullptr) {
					head->right->next = head->next->left;
				}
				// ָ������ƶ�
				head = head->next;
			}
			// ȥ��һ�������Ľڵ�
			leftmost = leftmost->left;
		}

		return root;
	}
};