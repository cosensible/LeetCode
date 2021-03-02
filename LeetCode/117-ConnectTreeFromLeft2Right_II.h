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
	// ����ÿһ���൱��һ������, ͨ���ϲ��������²�����
	// �����²������ͷ������ȷ��, �ڹ����²�����ʱ��Ҫһ���ƽڵ�
	Node* connect(Node* root) {
		if (root == nullptr) return root;
		Node *head = root; // �����ϲ������ָ��
		Node *dummy = new Node(); // �����²�������ƽڵ�

		while (head) {
			// �����ϲ�����, �������²�����
			Node *p2 = dummy;
			while (head) {
				if (head->left) { // ����Ӳ�Ϊ��, ����һ����������
					p2->next = head->left;
					p2 = p2->next;
				}
				if (head->right) { // �Ҷ��Ӳ�Ϊ��, ����һ������Ҷ���
					p2->next = head->right;
					p2 = p2->next;
				}
				head = head->next;
			}
			// ��ǰ�㹹�����, ��ʼ��һ�㹹��
			head = dummy->next;
			dummy->next = nullptr;
		}

		return root;
	}
};