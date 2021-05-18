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

		//拷贝各个节点, 新旧节点交织串连, 新节点random指向旧节点random
		Node *cur = head;
		while (cur) {
			Node *p = new Node(cur->val);
			p->next = cur->next;
			p->random = cur->random;
			cur->next = p;
			cur = cur->next->next;
		}
		//链表交织完毕, 修正新节点指向的random
		cur = head;
		while (cur) {
			Node *cp = cur->next;
			if (cp->random) cp->random = cp->random->next;
			cur = cur->next->next;
		}

		//将交织链表分离为原链表和拷贝链表
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