#include "common.h"
using namespace std;

class Solution_143 {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return;
		// �ҵ������е㣬�������Ϊǰ��������
		ListNode *p = head, *q = head;
		while (p->next&&p->next->next) {
			p = p->next->next;
			q = q->next;
		}
		ListNode *l1 = head, *l2 = q->next;
		q->next = nullptr;

		// ��ת�ڶ�������
		p = l2;
		while (p->next) {
			q = p->next;
			p->next = q->next;
			q->next = l2;
			l2 = q;
		}

		// ����ϲ���������
		while (l1&&l2) {
			p = l1->next;
			q = l2->next;
			l1->next = l2;
			l1 = p;
			l2->next = l1;
			l2 = q;
		}
	}
};

void test_143() {
	vector<int> vals = { 1,2,3,4,5 };
	ListNode *list = arr2list(vals);
	Solution_143().reorderList(list);
	printList(list); // 1 5 2 4 3
}