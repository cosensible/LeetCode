/* https://leetcode.com/problems/copy-list-with-random-pointer/ */


class Solution_138 {
public:
	class Node {
	public:
		int val;
		Node* next;
		Node* random;

		Node(int _val) {
			val = _val;
			next = nullptr;
			random = nullptr;
		}
	};

	Node* copyRandomList(Node* head) {
		if (head == nullptr) return nullptr;

		//���������ڵ�, �¾ɽڵ㽻֯����, �½ڵ�randomָ��ɽڵ�random
		Node *cur = head;
		while (cur) {
			Node *p = new Node(cur->val);
			p->next = cur->next;
			p->random = cur->random;
			cur->next = p;
			cur = cur->next->next;
		}
		//����֯���, �����½ڵ�ָ���random
		cur = head;
		while (cur) {
			Node *cp = cur->next;
			if (cp->random) cp->random = cp->random->next;
			cur = cur->next->next;
		}

		//����֯�������Ϊԭ����Ϳ�������
		Node *cplist = head->next;
		cur = head;
		while (cur) {
			Node *cp = cur->next;
			cur->next = cp->next;
			if (cp->next) cp->next = cp->next->next;
			cur = cur->next;
		}
		return cplist;
	}
};