#include "common.h"
using namespace std;

class Solution_92 {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (head == nullptr || head->next == nullptr || left == right) return head;
		ListNode *dummy = new ListNode(0, head);
		ListNode *pre = dummy; // pre ָ�����ת���ֵ�ǰһ���ڵ�
		int i = 1;
		for (; i < left; ++i) { // �ҵ�����ת���ֵĵ�һ���ڵ�
			pre = pre->next;
		}
		ListNode *cur = pre->next, *p = nullptr;
		for (; i < right; ++i) { // ִ������ת��pre->next ָ��ת�����ͷ��
			p = cur->next;
			cur->next = p->next;
			p->next = pre->next;
			pre->next = p;
		}
		return dummy->next;
	}
};


void test_92() {
	vector<int> vals = { 3,5 };
	ListNode *list = arr2list(vals);
	ListNode *ans = Solution_92().reverseBetween(list, 1, 2);
	printList(ans);
}